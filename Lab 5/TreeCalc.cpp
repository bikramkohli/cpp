// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree -> left != NULL)
        cleanTree(tree -> left);
    if (tree -> right != NULL)
        cleanTree(tree -> right);
    delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode* val1 = new TreeNode(val);
    if (val == "+" || val == "-" || val == "*" || val == "/") {
        val1 -> right = expressionStack.top();
        expressionStack.pop();

        val1 -> left = expressionStack.top();
        expressionStack.pop();

        expressionStack.push(val1);
    }

    else 
        expressionStack.push(val1);
    
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    if (tree != NULL) {
        cout << tree -> value << " ";

        if (tree -> left != NULL)
            printPrefix(tree -> left);

        if (tree -> right != NULL)
            printPrefix(tree -> right);
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    if (tree != NULL) {
        if (tree -> left != NULL) {
            cout << "(";
            printInfix(tree -> left);
        }   

        if (tree -> value == "+" || tree -> value == "-" || tree -> value == "*" || tree -> value == "/") 
            cout << " " + tree -> value + " ";
        else
            cout << tree -> value;

        if (tree -> right != NULL) {
            printInfix(tree -> right);
            cout << ")";
        }
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    if (tree != NULL) {
        if (tree -> left != NULL)
            printPostfix(tree -> left);

        if (tree -> right != NULL)
            printPostfix(tree -> right);

        cout << tree -> value << " ";
    }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    if (tree -> value == "+")
        return (calculate(tree -> left) + calculate(tree -> right));

    else if (tree -> value == "-")
        return (calculate(tree -> left) - calculate(tree -> right));

    else if (tree -> value == "*")
        return (calculate(tree -> left) * calculate(tree -> right));

    else if (tree -> value == "/")
        return (calculate(tree -> left) / calculate(tree -> right));

    else {
        return stoi(tree -> value);
    }
    return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    int i = calculate(expressionStack.top());
    return i;
}