// Bikram Kohli (bsk4uaa)
// hashTable.cpp

#include "hashTable.h"
using namespace std;

/*
int main() {
	hashTable test(11);
	test.insert("a");
	test.insert("b");
	test.insert("c");
	test.insert("d");
	test.insert("e");
	test.insert("f");
	test.insert("g");
	test.insert("h");
	test.insert("o");
	test.insert("ke");
	cout << "HERE " << test.find("ke") << endl;
	cout << "HERE " << test.find("bi") << endl;

	//test.printTable();
	return 0;
}
*/


hashTable::hashTable(int size) {
	if (!(checkPrime(size)))
		size = getNextPrime(size);
	myTable.resize(size);
	currSize = size;

	
	for (int i = 1; i <= size; i++) {
		list<string> x;
		myTable.push_back(x);
	}
}

void hashTable::printTable() {
	for (int i = 0; i < currSize; i++) {
		cout << i << ": \t" << myTable.at(i).front() << "\t" << myTable.at(i).back() << endl;
	}
}

hashTable::~hashTable() {
}


bool hashTable::find(string s) {
	list<string>::iterator i = myTable.at(hashFunc(s)).begin();
	while (i != myTable.at(hashFunc(s)).end()) {
		if (*i == s) {
			return true;
		}
		i++;
	}
	return false;
}


/*
bool hashTable::find(string s) {
	return (::find((myTable.at(hashFunc(s))).begin(),
		(myTable.at(hashFunc(s))).end(),
		hashFunc(s))
		!= (myTable.at(hashFunc(s))).end());	
}
*/



void hashTable::insert(string s) {
	myTable.at(hashFunc(s)).push_back(s);
}

int hashTable::hashFunc(string s) {
	int charsTotal = 1;
	for (int i = 0; i < s.length(); i++) {
		charsTotal += s[i];
	}
	return (charsTotal % currSize);
}


int hashTable::getNextPrime(unsigned int i) {
    while ( !checkPrime(++i) );
    return i; // all your primes are belong to us
}

bool hashTable::checkPrime(unsigned int p) {
	if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}