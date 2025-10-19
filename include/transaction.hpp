#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaction {
public:
    string buyer, seller, itemName, date, status;
    double price;

    Transaction(string b = "", string s = "", string i = "", double p = 0,
                string d = "", string st = "");
    void print();
};