#ifndef SHOP_HPP
#define SHOP_HPP
#include "Parts.hpp"
#include<vector>
#include<iostream>
using namespace std;

struct vertex;
struct adjVertex{
    vertex *v;
    float distance;
};

struct vertex{
    vertex() {
        this->visited = false;
        this->distance = 0;
    }
    string name;
    string[] airFrames;
    bool visited;
    int distance;
    vector<adjVertex> adj;
};

class ShopGraph {
    public:
        void addEdge(string shop1, string shop2, float dist, float driveTime);
        void addVertex(string shopName);
        void displayShopsData();
        void DFT(string sourceVertex);
        void setAllVerticesUnvisited();
        /*
        vertex* DijkstraAlgorithm(string start, string end);
        void shortestpath(string start, string end);
        */
    private:
        vector<vertex*> vertices;
        PartsTable inventory;
};

#endif
