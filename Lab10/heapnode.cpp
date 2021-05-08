// Bikram Kohli (bsk4uaa)
// heapnode.cpp

#include "heapnode.h"
using namespace std;

heapnode::heapnode() {	
	val = "";
	frequency = 0;
	left = NULL;
	right = NULL;
}

heapnode::heapnode(string s, int f, heapnode* l, heapnode* r) {
	val = s;
	frequency = f;
	left = l;
	right = r;
}

heapnode::~heapnode() {

}