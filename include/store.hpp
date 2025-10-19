#pragma once
#include "buyer.hpp"
#include "seller.hpp"
#include "transaction.hpp"
#include <vector>

class Store {
public:
    vector<Buyer> buyers;
    vector<Seller> sellers;
    vector<Transaction> transactions;

    void saveData();
    void loadData();
    void updateStatus();
    void menu();
};