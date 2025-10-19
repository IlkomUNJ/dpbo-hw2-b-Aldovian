#pragma once
#include "bank.hpp"
#include <string>
using namespace std;

class User {
protected:
    string username;
    BankAccount account;
public:
    User(string name = "", double balance = 0.0);
    string getUsername() const;
    BankAccount& getAccount();
};