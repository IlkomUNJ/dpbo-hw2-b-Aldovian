#pragma once
#include "user.hpp"
#include "item.hpp"
#include "transaction.hpp"
#include <vector>

class Buyer : public User {
public:
    Buyer(string name = "", double balance = 0.0);
    void buyItem(string seller, Item &item, int qty, vector<Transaction> &records);
};