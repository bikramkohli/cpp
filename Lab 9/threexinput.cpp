// bikram kohli (bsk4uaa)
// threexinput.cpp

#include <iostream>
#include <cstring>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int);

int main() {
	timer t;
	int x, n;

	cin >> x;	// reading inputs
	cin >> n;

	int result = threexplusone(x);

	t.start();
	for (int i = 0; i < n; i++) {
		threexplusone(x);
	}
	t.stop();

	cout << result << endl;
}