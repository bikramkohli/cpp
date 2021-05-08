// Bikram Kohli (bsk4uaa)
// Stack.cpp

#include <iostream>
#include "Stack.h"

Stack::Stack() {
	s = new List;
}

Stack::~Stack() {
	delete s;
}

void Stack::push(int e) {
	s -> insertAtTail(e);
}

void Stack::pop() {
	s -> removeAtTail(s -> last().retrieve());
}

int Stack::top() {
	return s -> last().retrieve();
}

bool Stack::empty() {
	return s -> isEmpty();
}