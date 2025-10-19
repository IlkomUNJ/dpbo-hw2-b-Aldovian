#include "../include/user.hpp"
User::User(string name, double balance) : username(name), account(name, balance) {}
string User::getUsername() const { return username; }
BankAccount& User::getAccount() { return account; }