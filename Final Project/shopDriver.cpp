#include "Shop.hpp"
#include <iostream>
#include <string>
using namespace std;

void ShopGraph::addEdge(string s1, string s2, float dist) {
	// Todo
}

void ShopGraph::addShop(string shopName) {
  bool found = false;
  for(int i = 0; i < shops.size(); i++){
    if(shops[i]->name == shopName){
      found = true;
    }
  }
  if(found == false){
    shop *s = new shop;
    s->name = shopName;
    shops.push_back(s);
  }
}

// Shows individual shop data
void ShopGraph::displayShopData(shop *s) {
	cout << s->name << endl;
	cout << s->address << endl;
	cout << s->Airframe << endl;
}

// Searches Nearby shops for needed part.
void ShopGraph::inquiry(int pNum, string af) {
	bool exists;
	for(int i = 0; i < shops.size(); i++) {
		if(shops[i]->Airframe == af) {
			part *tmp = shops[i]->inventory.searchParts(pNum);
			if(tmp->quantity>0)
			{
				displayShopData(shops[i]);
				cout << "Available: " << tmp->quantity;
				exists = true;
			}
		}
	}
	if(!exists)
		cout << "No available part within network" << endl;
}

void ShopGraph::setAllShopsUnvisited() {
	//Todo
}

void ShopGraph::setAirframe(shop* s) {
	cout << "Choose Airframe" << endl;

	string input;
	bool chosen = false;
	while(!chosen){
		cout<< "1. F16" << endl;
		cout<< "2. F15" <<  endl;
		cout<< "3. A10" << endl;
		getline(cin, input);

		if(input == "1") {
			s->Airframe = "F16";
			return;
		}
		if(input == "2") {
			s->Airframe = "F15";
			return;
		}
		if(input == "3") {
			s->Airframe = "A10";
			return;
		}
		else {
			cout << "Try again" << endl;
			continue;
		}
	}
}

// This will set home shop when program is in use.
shop* ShopGraph::search(string name) {
	int vSize = shops.size();
	shop *fnd = NULL;
	for(int i = 0; i < vSize; i++) {
		if(shops[i]->name== name)
			fnd = shops[i];
	}
	return fnd;
}

shop* ShopGraph::setHome(string name) {
	shop *tmp = search(name);
	if(tmp == NULL) {
		cout << "Error: Can't set home, shop doesn't exist" << endl;
		return NULL;
	}
	else {
		home = tmp;
		return home;
	}
}
