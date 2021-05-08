// Bikram Kohli (bsk4uaa) 09/11/2020
// bankAccount.cpp ... method and constructor bodies for bankAccount class

#include <iostream>
#include <string>
#include "bankAccount.h"
using namespace std;


// default constructor
bankAccount::bankAccount() {
	balance = 0.00;
}

// constructor with amount parameter
bankAccount::bankAccount(double amount) : balance(amount) {
}

// destructor
bankAccount::~bankAccount() {
}

double bankAccount::withdraw(double amount) {
	if (amount > balance) {
		return balance;
	}

	else {
		balance -= amount;
		return balance;
	}
}

double bankAccount::deposit(double amount) {
	balance += amount;
	return balance;
}

double bankAccount::getBalance() const {
	return balance;
}