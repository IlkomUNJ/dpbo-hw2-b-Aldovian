#pragma once
#include <string>
using namespace std;

class Item {
public:
    string name;
    double price;
    int stock;

    Item(string n = "", double p = 0, int s = 0);
    void reduceStock(int qty);
};