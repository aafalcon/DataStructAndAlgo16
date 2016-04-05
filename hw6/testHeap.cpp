#include "heap.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	MinHeap<string> heap(3);
	heap.add("Alden", 1);
	heap.add("Andrew", 3);
	heap.add("Bob", 2);
	heap.add("Joe", 7);
	cout << heap.peek() << " ";
	cout << heap.isEmpty() << endl;
	heap.remove();
	cout << heap.peek() << " ";
	cout << heap.isEmpty() << endl;
	heap.add("Billy", 1);
	cout << heap.peek() << " ";
	cout << heap.isEmpty() << endl;
	heap.remove();
	heap.remove();
	heap.remove();
	heap.remove();
	cout << heap.isEmpty() << endl;

	return 0;
}