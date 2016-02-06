#ifndef LLIST_H
#define LLIST_H

struct Node {
    int value;
    Node *next;
};

class LList {
	public:
		LList();
		~LList();
		Node* merge (Node*& first, Node*& second);
		void push(int n);
		int pull();
		Node* head;	
};

#endif