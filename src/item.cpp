#include "../include/item.hpp"
Item::Item(string n, double p, int s) : name(n), price(p), stock(s) {}
void Item::reduceStock(int qty) { stock -= qty; }