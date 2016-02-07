#ifndef LLIST_H
#define LLIST_H

struct Node {
    int value;
    Node *next;
	Node* merge (Node*& first, Node*& second);
};

#endif