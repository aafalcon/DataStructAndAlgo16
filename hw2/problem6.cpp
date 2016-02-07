#include "problem6.h"
#include <stdlib.h>

Node* Node::merge(Node*& first, Node*& second) {
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
}