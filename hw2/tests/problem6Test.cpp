#include "../problem6.h"
#include <iostream>

using namespace std;

int main () {
	Node* head= new Node;
	Node* second= new Node;
	Node* third= new Node;
	Node* head2= new Node;
	Node* second2= new Node;
	Node* third2= new Node;
	head->value= 4;
	second->value= 6;
	third->value= 8;
	head2->value= 1;
	second2->value= 5;
	third2->value= 7;
	// First list
	head->next= second;
	second->next= third;
	third->next= NULL;
	// Second list
	head2->next= second2;
	second2->next= third2;
	third2->next= NULL;
	/*
	// Null tests
	Node* nothing= NULL;
	Node* nothing2= NULL;
	*/

	Node* merged= head->merge(head, head2);
	Node* temp= merged;

	for (int i=0; i<6; i++)
	{
		cout << temp->value << endl;
		temp= temp->next;
	}

	if (head == NULL && head2 == NULL)
	{
		cout << "Success: first and second were set to NULL" << endl;
	}
	else
	{
		cerr << "Failure: first and/or second not set to NULL" << endl;
	}

	delete head;
	delete second;
	delete third;
	delete head2;
	delete second2;
	delete third2;
	delete merged;

	return 0;
}