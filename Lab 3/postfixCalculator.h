// Bikram Kohli
// postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"

using namespace std;

class postfixCalculator {
public:
	postfixCalculator();	// default constructor
	~postfixCalculator();
	void add();				// adds top 2 values in stack
	void subtract();		// subtracts top 2 values in stack
	void multiply();		// multiplies top 2 values in stack
	void divide();			// divides top 2 values in stack
	void negate();			// negates top value in stack
	Stack* getStack();		// returns pointer to stack

private:
	Stack* st;
};

#endif