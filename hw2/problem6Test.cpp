#include "problem6.h"
#include <iostream>

using namespace std;

int main () {
	LList list1;
	LList list2;
	list1.push(1);
	list1.push(2);
	list1.push(3);
	list2.push(3);
	list2.push(4);
	list2.push(5);
	cout<< list1.pull() << list1.pull() << endl;
	list1.head= list1.merge(list1.head, list2.head);
	while (list1.head != NULL)
	{
		cout << list1.pull();
	}
	cout << endl;

	return 0;
}