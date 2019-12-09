#ifndef SHOP_HPP
#define SHOP_HPP
#include "Parts.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class PartsTable;
struct shop;
struct similarShop{
    shop *s;
};

// Shop node contains hash table of parts.
struct shop{
    shop() {
        this->Airframe = "";
        this->visited = false;
        this->distance = 0;
    }
    int bNum;
    PartsTable inventory;
    string name;
    string Airframe;
    string address;
    bool visited;
    int distance;
    vector<similarShop> adj;
};

class ShopGraph {
    public:
        void addEdge(string shop1, string shop2, float dist);
        void addShop(string shopName);
        void loadParts(shop *s);
        void displayShopData(shop *s);
        void setAllShopsUnvisited();
        void setAirframe(shop *s);
        void inquiry(int pNum, string af);
        shop* search(string sName);
        shop* setHome(string sName);
    private:
        vector<shop*> shops;
        shop *home;
};

#endif
