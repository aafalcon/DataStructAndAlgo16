#include "problem6.h"
#include <stdlib.h>

LList::LList() {
	head= NULL;
}

LList::~LList() {
    if (head != NULL)
    {
    	Node* temp= head;  
    	while (head != NULL)
		{
			Node* toDelete= temp;
			temp= temp->next;
			delete toDelete;
		}
    }
}

Node* LList::merge(Node*& first, Node*& second) {
	Node* start;
	if (first == NULL)
	{
		start= second;
		second= NULL;
	}
	else if (second == NULL)
	{
		start= first;
		first= NULL;
	}
	else
	{
		if (first->value <= second->value)
		{
			start= first;
			start->next= merge(first->next, second);
			first= NULL;
		}
		else
		{
			start= second;
			start->next= merge(first, second->next);
			second= NULL;
		}
	}

	return start;

	/* Attempt 1
	if (first->val <= second->val)
	{
		if (second->val <= first->next->val) 
		{
			Node* temp= first->next;
			first->next= second;
			Node* temp2= first->next->next;
			first->next->next= temp;
			second= temp2;
			temp= NULL;
			temp2= NULL:
		}

		if (second != NULL)
		{
			merge(first->next, second);
		}
		
	}
	else
	{
		merge(second, first);
	}
	*/
	
}

void LList::push(int n) {
	Node* p = new Node;
	p->value= n;
	p->next= head;
	head= p;
}

int LList::pull() {
	Node* temp= head;
	head= head->next;
	int pullval= temp->value;
	delete temp;
	return pullval;
}
