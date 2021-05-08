// Bikram Kohli (bsk4uaa)
// ListNode.cpp

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode::ListNode() {
	value = 0;
	next = NULL;
	previous = NULL;
}

ListNode::ListNode(int x) {
	value = x;
	next = NULL;
	previous = NULL;
}
