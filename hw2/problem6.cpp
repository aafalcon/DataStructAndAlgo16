#include "problem6.h"
#include <stdlib.h>

Node* Node::merge(Node*& first, Node*& second) {
	Node* start;
	// when first is end of list
	if (first == NULL)
	{
		start= second;
		second= NULL;
	}
	// when second is end of list
	else if (second == NULL)
	{
		start= first;
		first= NULL;
	}
	else
	{
		// if first is less than second place the start pointer to first
		if (first->value <= second->value)
		{
			start= first;
			// run again with next value in first
			start->next= merge(first->next, second);
			first= NULL;
		}
		// else place the start pointer to second
		else
		{
			start= second;
			// run again with next value in second
			start->next= merge(first, second->next);
			second= NULL;
		}
	}

	return start;	
}