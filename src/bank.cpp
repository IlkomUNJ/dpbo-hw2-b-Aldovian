#include "../include/bank.hpp"
#include <iostream>
using namespace std;

BankAccount::BankAccount(string owner, double balance) : owner(owner), balance(balance) {}
void BankAccount::deposit(double amount) { balance += amount; }
bool BankAccount::withdraw(double amount) {
    if (balance >= amount) { balance -= amount; return true; }
    return false;
}
double BankAccount::getBalance() const { return balance; }
string BankAccount::getOwner() const { return owner; }