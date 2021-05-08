// bikram kohli (bsk4uaa)
// mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

int main() {

	int x, y;

	cin >> x;		// reading inputs
	cin >> y;	

	cout << "Product: " << product(x, y) << endl;
	cout << "Power: " << power(x, y) << endl;
	return 0;
}