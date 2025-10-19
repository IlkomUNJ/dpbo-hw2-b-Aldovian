#include "../include/seller.hpp"
#include <iostream>
using namespace std;

Seller::Seller(string name, double balance) : User(name, balance) {}

void Seller::addItem() {
    Item it;
    cout << "Masukkan nama barang: ";
    cin >> it.name;
    cout << "Masukkan harga: ";
    cin >> it.price;
    cout << "Masukkan stok: ";
    cin >> it.stock;
    items.push_back(it);
    cout << "Barang berhasil ditambahkan!\n";
}