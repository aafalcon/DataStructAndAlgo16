#ifndef LLIST_H
#define LLIST_H

struct Node {
    int value;
    Node *next;
};

class LList {
	public:
		Node* merge (Node*& first, Node*& second);
	private:
		Node* head;
}