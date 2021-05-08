// Bikram Kohli (bsk4uaa)
// ListItr.cpp

#include <iostream>
#include "ListItr.h"
using namespace std;

ListItr::ListItr() {
	current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
	current = theNode;
}

// checking if the iterator is pointing past the end position
bool ListItr::isPastEnd() const {
	if (current -> next == NULL) {
		return true;
	}

	else {
		return false;
	}
}

// checking if the iterator is pointing before the first position
bool ListItr::isPastBeginning() const {
	if (current -> previous == NULL) {
		return true;
	}

	else {
		return false;
	}
}

void ListItr::moveForward() {
	if (!isPastEnd()) {
		current = current -> next;
	}
}

void ListItr::moveBackward() {
	if (!isPastBeginning()) {
		current = current -> previous;
	}
}

int ListItr::retrieve() const {
	return current -> value;
}