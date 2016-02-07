#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt * list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert first item at the head.
  list->insert(0, 3);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after 1 insertion." << endl;
  } else {
    cout << "FAIL: List is empty after 1 insertion." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after 1 insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after 1 insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 3) {
    cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  // Remove a single item from the list
  list->remove(0);

  // Check if the list is empty after removal of 1 element.
  if (list->empty()) {
    cout << "SUCCESS: List is empty." << endl;
  } else {
    cout << "FAIL: List is not empty when it should be." << endl;
  }

  // ***Make insertions***
  // Insert 2 items to head
  list->insert(0, 1);
  list->insert(0, 2);
  // Insert 1 item to tail
  list->insert(2, 3);
  // Insert item in the middle of list
  list->insert(1, 4);
 
  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after 4 insertions." << endl;
  } else {
    cout << "FAIL: List is empty after 4 insertions." << endl;
  }

  if (list->size() == 4) {
    cout << "SUCCESS: List has size 4 after 1 insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after 1 insertion.";
    cout << endl;
  }

  // Check if the values are correct.
  if (list->get(0) == 2 && list->get(1) == 4 && list->get(2) == 1 &&
      list->get(3) == 3) {
    cout << "SUCCESS: [2,4,1,3] list is ordered correctly" << endl;
  } else {
    cout << "FAIL: list is ordered incorrectly" << endl;
  }

  // ***Remove middle item***
  list->remove(1);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after 1 removal." << endl;
  } else {
    cout << "FAIL: List is empty after 1 removal." << endl;
  }

  if (list->size() == 3) {
    cout << "SUCCESS: List has size 3 after 1 removal." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after 1 removal.";
    cout << endl;
  }

  // Check if the values are correct.
  if (list->get(0) == 2 && list->get(1) == 1 && list->get(2) == 3) {
    cout << "SUCCESS: [2,1,3] list is ordered correctly" << endl;
  } else {
    cout << "FAIL: list is ordered incorrectly" << endl;
  }

  // ***Remove head item***
  list->remove(0);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after 2 removals." << endl;
  } else {
    cout << "FAIL: List is empty after 2 removals." << endl;
  }

  if (list->size() == 2) {
    cout << "SUCCESS: List has size 2 after 2 removals." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after 2 removal.";
    cout << endl;
  }

  // Check if the values are correct.
  if (list->get(0) == 1 && list->get(1) == 3) {
    cout << "SUCCESS: [1,3] list is ordered correctly" << endl;
  } else {
    cout << "FAIL: list is ordered incorrectly" << endl;
  }

  // ***Remove tail item***
  list->remove(1);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after 3 removals." << endl;
  } else {
    cout << "FAIL: List is empty after 3 removals." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after 3 removals." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after 3 removals.";
    cout << endl;
  }

  // Check if the values are correct.
  if (list->get(0) == 1) {
    cout << "SUCCESS: [1] list is ordered correctly" << endl;
  } else {
    cout << "FAIL: list is ordered incorrectly" << endl;
  }

  // ***Remove last item***
  list->remove(0);

  // Check if list is empty
  if (list->empty()) {
    cout << "SUCCESS: List is empty after 4 removals." << endl;
  } else {
    cout << "FAIL: List is not empty after 4 removals." << endl;
  }

  // Clean up memory.
  delete list;
}
