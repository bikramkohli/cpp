// Bikram Kohli (bsk4uaa)
// bitCounter.cpp

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int numOnes(int i) {
	if (i == 0) 
		return 0;

	else if (i % 2 == 0)
		return numOnes(i/2);

	else
		return (1 + numOnes(i/2));
}

string baseConverter(string num, int start, int end) {
	int base = 0;
	int dec = 0;
	int rem = 0;
	string returnStr = "";

	for (int i = num.size() - 1; i > -1; i--) {
		int x = (int)num[i];
		if (x > 57)
			x -= 55;
		else
			x -= '0';

		dec += x * pow(start, base);
		base++;
	}

	while (dec != 0) {
		rem = dec % end;
		dec /= end;
		char c = '0' + rem;
		returnStr = c + returnStr;
	}

	return returnStr;
}

int main(int argc, char** argv) {
	// ./a.out 15 1010 2 4
	// argv[0] -> ./a.out
	// argv[1] -> 15
	// numOnes(argv[1])
	// baseConverter(argv[2], argv[3], argv[4])
	if (argc == 0) {
		cout << "error" << endl;
		return 1;
	}

	int argv1 = atoi(argv[1]);
	int argv3 = atoi(argv[3]);
	int argv4 = atoi(argv[4]);

	cout << argv1 << " has " << numOnes(argv1) << " bit(s)" << endl;
	cout << argv[2] << " (base " << argv3 << ") = " << baseConverter(argv[2], argv3, argv4) << " (base " << argv4 << ")" << endl;
	return 0;
}

