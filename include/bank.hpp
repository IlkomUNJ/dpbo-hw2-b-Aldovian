#pragma once
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;
public:
    BankAccount(string owner = "", double balance = 0.0);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    string getOwner() const;
};