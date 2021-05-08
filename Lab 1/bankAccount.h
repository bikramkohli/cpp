// Bikram Kohli (bsk4uaa) 09/11/2020
// bankAccount.h ... file for defining bankAccount class

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;

class bankAccount {
public:
	bankAccount();					// default constructor
	bankAccount(double amount);		// constructor with amount parameter
	~bankAccount();					// destructor

	double withdraw(double amount);
	double deposit(double amount);
	double getBalance() const;

private:
	double balance;
};

#endif