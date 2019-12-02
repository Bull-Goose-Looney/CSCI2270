#include "Parts.hpp"
#include <iostream>
#include <string>
using namespace std;

PartsTable::PartsTable(int bsize) { // Constructor
	  this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

part* PartsTable::searchParts(int pNum) {
		part* find = table[idx];
		while(find) {
			if(find->partNumber == pNum)
				return find;
			find = find->next;
		}
		return NULL;
}

part* PartsTable::createPart(int partNum, part* next, string pName, 
string man, string sCode, int bNum, int dNum, int count, float cost) {
	  part* np = new part;
    np->partNumber = partNum;
    np->partName = pName;
    np->manufacturer = man;
    np->shopCode = sCode;
    np->bNum = bNum;
    np->dNum = dNum;
    np->cost = cost;
    np->quantity++;
    np->next = next;
    return np;
}

unsigned int PartsTable::hashSlinging(int partNum, string pName) { // hash function
		return partNum % tableSize
}

bool PartsTable::insert(int pNum) {
	if(!searchParts(pNum)) {
		int insert = hashSlinging(pNum);
		part *n = createPart(pNum, table[insert]);
		return true;
	}
  else { // Part is already in database.
  	part *add = searchParts(pNum);
  	add->quantity++; // Update number of parts available.
  	return false;
  }
}

void PartsTable::printParts() {

}

