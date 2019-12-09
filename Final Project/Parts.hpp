#ifndef PARTS_HPP
#define PARTS_HPP
#include <string>
using namespace std;

struct part {
    int partNumber;
    string partName; // Nomenclature
    string shopCode; // Owning shop
    string airframes[3]; // Compatible aircraft
    string location;
    int quantity; // Number of same part available
    string manufacturer;
    float cost;
    struct part* next;
};

class PartsTable {
    int tableSize; // Number of linked lists
    part* *table; // Pointer to an array containing buckets
    part* createPart(int partNum, part* next);
public:
    PartsTable();  // Constructor
    unsigned int hashFn(int pNum); // hash function
    bool insert(string n, int num, string m, float cst,
    string af1, string af2, string af3); // Table insert
    void printParts();
    void displayPartInfo(int pNum);
    part* searchParts(int pNum);
};
#endif
