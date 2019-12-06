#ifndef SHOP_HPP
#define SHOP_HPP
#include "Parts.hpp"
#include<vector>
#include<iostream>
using namespace std;

struct shop;
struct similarShops{
    vertex *v;
    float distance;
};

struct shop{
    string name;
    string[] airFrames;
    PartsTable parts;
    bool visited;
    vector<similarShops> adj;
};

class ShopGraph {
    public:
        void addEdge(string shop1, string shop2, float dist, float driveTime);
        void addVertex(string shopName);
        void displayShopsData();
        void DFT(string sourceVertex);
        void setAllVerticesUnvisited();
    private:
        vector<shop*> shops;
};

#endif
