// Bikram Kohli (bsk4uaa)
// prelab4.cpp

#include <iostream>
#include <string>
using namespace std;

void sizeOfTest() {
	int i = -1;
	unsigned int ui = 1;
	float f = 1.23;
	double d = 1.23;
	char c = 'a';
	bool b = true;
	int* ip = NULL;
	char* cp = NULL;
	double* dp = NULL;

	cout << "Size of int: " << sizeof(i) << endl;
	cout << "Size of unsigned int: " << sizeof(ui) << endl;
	cout << "Size of float: " << sizeof(f) << endl;
	cout << "Size of double: " << sizeof(d) << endl;
	cout << "Size of char: " << sizeof(c) << endl;
	cout << "Size of bool: " << sizeof(b) << endl;
	cout << "Size of int*: " << sizeof(ip) << endl;
	cout << "Size of char*: " << sizeof(cp) << endl;
	cout << "Size of double*: " << sizeof(dp) << endl;
}

void overflow() {
	unsigned int max = 4294967295;	//0xffffffff
	cout << max << " + 1 = " << (max + 1) << endl;
}

void outputBinary(unsigned int i) {
	int rem = 1;
	string returnStr = "00000000000000000000000000000000";
	int index = 31;
	while (i != 0) {
		rem = i % 2;
		i /= 2;
		char c = '0' + rem;
		returnStr[index] = c;
		
		index--;
	}
	cout << returnStr << endl;
}

int main() {
	sizeOfTest();
	overflow();
	int input;
	cin >> input;
	outputBinary(input);
	return 0;
}