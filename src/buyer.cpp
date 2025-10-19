#include "../include/buyer.hpp"
#include <iostream>
#include <ctime>
using namespace std;

Buyer::Buyer(string name, double balance) : User(name, balance) {}

void Buyer::buyItem(string seller, Item &item, int qty, vector<Transaction> &records) {
    double total = item.price * qty;
    if (account.getBalance() < total) {
        cout << "Saldo tidak cukup!\n";
        return;
    }
    if (item.stock < qty) {
        cout << "Stok tidak cukup!\n";
        return;
    }

    account.withdraw(total);
    item.reduceStock(qty);

    time_t now = time(0);
    string date = ctime(&now);
    date.pop_back();

    Transaction t(username, seller, item.name, total, date, "Paid");
    records.push_back(t);
    cout << "Pembelian berhasil! (Status: Paid)\n";
}