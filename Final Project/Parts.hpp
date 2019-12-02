#ifndef PARTS_HPP
#define PARTS_HPP
#include <string>
using namespace std;

struct part {
    int partNumber;
    string partName; // Nomenclature
    string shopCode; // Owning shop
    int bNum; // Bin number
    int dNum; // Drawer/Shelf number
    int quantity; // Number of same part available
    string manufacturer;
    float cost;
    struct part* next;
};

class PartsTable {
    int tableSize; // No. of buckets (linked lists)
    part* *table; // Pointer to an array containing buckets
    part* createPart(int partNum, node* next);
public:
    PartsTable(int bsize);  // Constructor
    unsigned int hashSlinging(int key); // hash function
    bool insert(int pNum, float cost, string name, string loc, string man);
    void printParts();
    part* searchParts(int pNum);
};
#endif
