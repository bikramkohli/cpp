// Bikram Kohli (bsk4uaa)
// Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"


class Stack {
public:
	Stack();
	~Stack();

	void push(int e);
	void pop();
	int top();
	bool empty();

private:
	List* s;
};

#endif