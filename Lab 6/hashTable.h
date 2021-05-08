// Bikram Kohli (bsk4uaa)
// hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class hashTable{
public:
	hashTable(int size);
	~hashTable();
	bool find(string s);
	void insert(string s);
	int hashFunc(string s);
	void printTable();
private:
	vector<list<string>> myTable;
	int getNextPrime(unsigned int i);
	bool checkPrime(unsigned int p);
	int currSize;
};

#endif