#include "problem6.h"

LList::LList() {
	head= NULL;
}

Node* LList::merge(Node*& first, Node*& second) {
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

		if ()
		merge(first->next, second);
	}
	else
	{
		merge(second, first);
	}
	
}