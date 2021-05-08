// Bikram Kohli (bsk4uaa)

#include <iostream>
using namespace std;

// recursive function that computes x^n for non-negative numbers
int xton(int x, int n) {
	// base case
	if (n == 0) {
		return 1;
	}

	// recursive
	return x * xton(x, n - 1);
}

int main() {
	int x, n;

	// user input for base value
	cout << "Enter base value (x): " << endl;
	cin >> x;

	// user input for exponent value
	cout << "Enter exponent value (n): " << endl;
	cin >> n;

	cout << xton(x, n) << endl;

	return 0;
}
