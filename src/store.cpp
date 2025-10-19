#include "../include/store.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Store::saveData() {
    ofstream file("store_data.txt");
    if (!file) return;
    for (auto &t : transactions) {
        file << t.buyer << "," << t.seller << "," << t.itemName << ","
             << t.price << "," << t.date << "," << t.status << endl;
    }
    file.close();
    cout << "Data berhasil disimpan!\n";
}

void Store::loadData() {
    ifstream file("store_data.txt");
    if (!file) return;
    transactions.clear();

    string buyer, seller, item, date, status;
    double price;
    while (getline(file, buyer, ',')) {
        getline(file, seller, ',');
        getline(file, item, ',');
        file >> price;
        file.ignore();
        getline(file, date, ',');
        getline(file, status);
        transactions.push_back(Transaction(buyer, seller, item, price, date, status));
    }
    file.close();
    cout << "Data transaksi berhasil dimuat!\n";
}

void Store::updateStatus() {
    string buyer;
    cout << "Masukkan nama buyer yang transaksinya ingin diubah: ";
    cin >> buyer;
    for (auto &t : transactions) {
        if (t.buyer == buyer) {
            cout << "Ubah status untuk transaksi: " << t.itemName << endl;
            cout << "1. Complete\n2. Cancelled\nPilih: ";
            int opt; cin >> opt;
            if (opt == 1) t.status = "Complete";
            else if (opt == 2) t.status = "Cancelled";
        }
    }
    cout << "Status transaksi diperbarui!\n";
}

void Store::menu() {
    loadData();
    int pilih;
    do {
        cout << "\n=== ONLINE STORE ===\n";
        cout << "1. Tambah Seller\n";
        cout << "2. Tambah Buyer\n";
        cout << "3. Seller Tambah Barang\n";
        cout << "4. Buyer Beli Barang\n";
        cout << "5. Lihat Transaksi\n";
        cout << "6. Ubah Status Transaksi\n";
        cout << "7. Simpan & Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string name; double bal;
            cout << "Nama seller: "; cin >> name;
            cout << "Saldo awal: "; cin >> bal;
            sellers.push_back(Seller(name, bal));
        } 
        else if (pilih == 2) {
            string name; double bal;
            cout << "Nama buyer: "; cin >> name;
            cout << "Saldo awal: "; cin >> bal;
            buyers.push_back(Buyer(name, bal));
        } 
        else if (pilih == 3 && !sellers.empty()) {
            sellers[0].addItem();
        } 
        else if (pilih == 4 && !buyers.empty() && !sellers.empty()) {
            if (sellers[0].items.empty()) {
                cout << "Belum ada barang!\n";
                continue;
            }
            buyers[0].buyItem(sellers[0].getUsername(), sellers[0].items[0], 1, transactions);
        } 
        else if (pilih == 5) {
            for (auto &t : transactions) t.print();
        } 
        else if (pilih == 6) {
            updateStatus();
        } 
        else if (pilih == 7) {
            saveData();
            cout << "Keluar dari program...\n";
        }

    } while (pilih != 7);
}