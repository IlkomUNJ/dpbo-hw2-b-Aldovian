#pragma once
#include "user.hpp"
#include "item.hpp"
#include <vector>

class Seller : public User {
public:
    vector<Item> items;
    Seller(string name = "", double balance = 0.0);
    void addItem();
};