#include "Parts.hpp"
#include <iostream>
#include <string>
using namespace std;


part* PartsTable::createPart(int pNum, part *next) {
		part* np = new part;
		cout << "howdy" << endl;
		np->partNumber = pNum;
		np->next = next;
		return np;
}

PartsTable::PartsTable() { // Constructor
		this->tableSize=1000;
		table = new part*[1000];
		for(int i=0;i<1000;i++)
				table[i] = nullptr;
}


unsigned int PartsTable::hashFn(int partNum) { // hash function
		int val = partNum % tableSize;
		return val;
}

part* PartsTable::searchParts(int pNum) {
		int idx = hashFn(pNum);
		part *find = table[idx];
		while(find!=NULL) {
			if(find->partNumber == pNum){
				return find;
			}
			find = find->next;
		}
		return NULL;
}

bool PartsTable::insert(string name, int num, string m, 
float cst, string af1, string af2, string af3) { // Insert part in hash table

	if(!searchParts(num)) {
		int insert = hashFn(num);
		part *n = new part;
		n->next = NULL;
		table[insert] = n;
		n->partName = name;
		n->partNumber = num;
		n->quantity++;
		n->manufacturer = m;
		n->cost = cst;
		n->airframes[0] = af1;
		n->airframes[1] = af2;
		n->airframes[2] = af3;
		return true;
	}
	else { // Part is already in database.
		part *add = searchParts(num);
		add->quantity++; // Update number of parts available.
	cout << "Quantity of " << add->partName << "s: " << add->quantity;
		return false;
	}
}

void PartsTable::printParts() {
		part *crl;
		for (int i = 0; i < tableSize; i++) {
				crl = table[i];
				while(crl!=NULL) {
						cout << "Nomenclature: "; 
						cout << crl->partName<< endl;
						cout << "Part Number: ";
						cout << crl->partNumber << endl; 
						crl = crl->next;
				}
		}
}

void PartsTable::displayPartInfo(int pNum) {
	part *tmp = searchParts(pNum);
	if(tmp==NULL)
		cout << "Part Not Found" << endl;
	else {
		cout << tmp->partName << " Location: " << tmp->location << endl;
		cout << "Quantity in stock: " << tmp->quantity << endl;
	}
}

