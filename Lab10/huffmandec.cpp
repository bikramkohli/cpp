// Bikram Kohli (bsk4uaa)
// huffmandec.cpp

#include "heap.h"
#include "heapnode.h"
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

string decode(string s, heapnode* node) {
	if (node -> left == NULL && node -> right == NULL) 
		return node -> val;

	else if (s[0] == '1') 
		return decode(s.substr(1), node -> right);	
	
	else if (s.length() == 1) {
		if (s == "0") 
			return node -> left -> val;
		else if (s == "1")
			return node -> right -> val;
	}

	// basically else if (s[0] == '0')
	// doing it this way so that function always has return 
	return decode(s.substr(1), node -> left);
}

int main (int argc, char** argv) {
	map<string, string> codes;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        codes[character] = prefix;
    }

    // creating huffman tree from prefix codes
    heapnode* root = new heapnode;

    for (auto item : codes) {
    	heapnode* temp = root;
    	string first = item.first;
    	string second = item.second;

    	for (int i = 0; i < second.length(); i++) {
    		if (second[i] == '1') {
    			if (temp -> right != NULL) 
    				temp = temp -> right;
    			else {
    				heapnode* newLeaf = new heapnode;
    				temp -> right = newLeaf;
    				if (i == second.length() - 1)
    					newLeaf -> val = first; 
    				else
    					temp = temp -> right;
    			}
    		}

    		else if (second[i] == '0') {
    			if (temp -> left != NULL) 
    				temp = temp -> left;
    			else {
    				heapnode* newLeaf = new heapnode;
    				temp -> left = newLeaf;
    				if (i == second.length() - 1)
    					newLeaf -> val = first;
    				else 
    					temp = temp -> left;
    			}
    		}

    	}
    }

   	// read in the second section of the file: the encoded message
   	// decode each section of 1s and 0s as they come up
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
       	cout << decode(bits, root);
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    cout << endl;

/*
    heapnode* temp2 = root;
    string retString = "";
    cout << allbits << endl;
    // reading through encoded file
    for (int i = 0; i < allbits.length(); i++) {
    	if (allbits[i] == '1') {
    		if (temp2 -> right != NULL)
    			temp2 = temp2 -> right;
    		else {
    			retString += temp2 -> val;
    			temp2 = root;
    		}
    	}

    	else if (allbits[i] == '0') {
    		if (temp2 -> left != NULL)
    			temp2 = temp2 -> left;
    		else {
    			retString += temp2 -> val;
    			temp2 = root;
    		}
    	}
	}
	*/

    

    return 0;
}