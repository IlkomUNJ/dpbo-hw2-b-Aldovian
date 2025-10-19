#include "../include/transaction.hpp"
#include <iostream>
using namespace std;

Transaction::Transaction(string b, string s, string i, double p, string d, string st)
    : buyer(b), seller(s), itemName(i), price(p), date(d), status(st) {}

void Transaction::print() {
    cout << "Buyer: " << buyer
         << " | Seller: " << seller
         << " | Item: " << itemName
         << " | Price: " << price
         << " | Date: " << date
         << " | Status: " << status << endl;
}