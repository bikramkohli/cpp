// Bikram Kohli (bsk4uaa)
// heapnode.h

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <string>
using namespace std;

class heapnode {
public:
	heapnode();
	heapnode(string s, int f, heapnode* l, heapnode* r);
	~heapnode();

	string val;
	int frequency;
	heapnode* left;
	heapnode* right;
private:
};

#endif