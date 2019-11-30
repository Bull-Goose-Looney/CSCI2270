#ifndef PARTS_HPP
#define PARTS_HPP
#include <string>
using namespace std;

struct part {
    int partNumber;
    string partName;
    string shop; // Owning shop
    int bNum; // Bin number
    int dNum; // Drawer/Shelf number
    int quantity; // Number of same part available
    string manufacturer;
    float cost;
    struct node* next;
};

class PartsTable {
    int tableSize; // No. of buckets (linked lists)
    node* *table; // Pointer to an array containing buckets
    node* createNode(int key, node* next);
public:
    PartsTable(int bsize);  // Constructor
    unsigned int hashFunction(int key); // hash function
    bool insert(int pNum, float cost, string name, string loc, string man);
    void printPartsList();
    part* searchParts(int pNum, string pName);
};
#endif
