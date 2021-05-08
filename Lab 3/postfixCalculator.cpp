// Bikram Kohli (bsk4uaa)
// postfixCalculator.cpp

#include <iostream>
#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator() {
	st = new Stack;
}

postfixCalculator::~postfixCalculator() {

}

void postfixCalculator::add() {
	int first = st -> top();
	st -> pop();

	int second = st -> top();
	st -> pop();

	st -> push(first + second);
}

void postfixCalculator::subtract() {
	int first = st -> top();
	st -> pop();

	int second = st -> top();
	st -> pop();

	st -> push(second - first);
}


void postfixCalculator::multiply() {
	int first = st -> top();
	st -> pop();

	int second = st -> top();
	st -> pop();

	st -> push(first * second);
}

void postfixCalculator::divide() {
	int first = st -> top();
	st -> pop();

	int second = st -> top();
	st -> pop();

	st -> push(second / first);
}

void postfixCalculator::negate() {
	int first = st -> top();
	st -> pop();

	st -> push(-1 * first);
}


Stack* postfixCalculator::getStack() {
	return st;
}
