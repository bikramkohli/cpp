// Bikram Kohli (bsk4uaa)
// testPostfixCalculator.cpp

#include <iostream>
#include <string>
#include "postfixCalculator.h"

using namespace std;

int main() {
	postfixCalculator pc;

	string token;
	while (cin >> token) {
		if (token == "+") {
			pc.add();
		}

		else if (token == "-") {
			pc.subtract();
		}


		else if (token == "*") {
			pc.multiply();
		}

		else if (token == "/") {
			pc.divide();
		}
		
		else if (token == "~") {
			pc.negate();
		}

		else {
			pc.getStack() -> push(stoi(token));
		}

	}

	cout << pc.getStack() -> top() << endl;
	return 0;
}