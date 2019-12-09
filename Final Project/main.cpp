#include "Shop.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int split(string str, char c, string fill[])
{
    if (str.length() == 0) {
        return 0;
    }
    
    string word = "";
    int counter = 0;
    str = str + c;
    
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
        	if (word.length() == 0)
        	{
        	    continue;
        	}
        	
        	fill[counter] = word;
            counter++;
            word = "";
        } 
        else 
        {
            word = word + str[i];
        }
    } 
    return counter;
}

// Reads from parts file and populates hash table.
void populateInventory(string partsList, PartsTable h) { 
	ifstream data;
	data.open(partsList);
	string temp[7];
	int partNum;
	string partName;
	string manufacturer;
	float cost;
	string airFrames[3]; // Max: 3 Airframes
	string tmp;

	string line;
	if(data.is_open()) {
		while(getline(data, line)) {
			split(line, ',', temp);
			tmp = temp[3];
			tmp[0] = ' ';
			partName = temp[0];
			partNum = stoi(temp[1]);
			manufacturer = temp[2];
			cost = stof(tmp);
			airFrames[0] = temp[4];
			airFrames[1] = temp[5];
			airFrames[2] = temp[6];

			h.insert(partName, partNum, manufacturer, 
			cost, airFrames[0], airFrames[1], airFrames[2]);
		}
		data.close();
	}
}


void addShops(ShopGraph network) {
	// Add a bunch of shops w/ diff airframes.
}

void displayMenu(string name){
	cout<<  "======" <<name<< "======" << endl;
	cout<< "1. Search" << endl;
	cout<< "2. Manage Part" <<  endl;
	cout<< "3. Inquire" << endl;
	cout<< "4. Order Part" << endl;
	cout<< "5. Quit" << endl;
}
 
int main(int argc, char const *argv[]) {
	ShopGraph network;
	addShops(network); // TODO finish fn
	string partsList = argv[1];
	string input;

	// Set shop location and name.
	cout << "Enter shop name: ";
	getline(cin, input);
	network.addShop(input);
	shop *home = network.setHome(input); // Working shop;
	network.setAirframe(home); // Set airframe
	populateInventory(partsList, home->inventory); // Add partslist to inv.
	home->inventory.printParts();
	int choice = 0;
	while(choice!=5) {
		displayMenu(home->name);
		getline(cin, input);
		choice = stoi(input);

		switch(choice) {
			case 1: {
				
				cout << "Enter part number" << endl;
				getline(cin, input);
				int num = stoi(input);
				home->inventory.displayPartInfo(num);
				cout << endl;
				break;
			}
			case 2: 
			{
				cout << "Enter part number" << endl;
				getline(cin, input);
				int num = stoi(input);
				part *tmp = home->inventory.searchParts(num);
				if(tmp == NULL) {
					bool chc = false;
					while(chc == false) {
						cout << "Add Part to inventory?" << endl;
						cout << tmp->cost << "[y/n]" << endl;
						getline(cin, input);
						if(input=="y"||input=="Y") {
							// Insert fn.
							cout << "Part Added" << endl;
							break;
						}
						if(input=="n"||input=="N") {
							break;
						}
						else
							continue;
					}
				}
				string pMenu;
				int c = 0;
				while(c!=4) {
					cout << "Choose an Option" << endl;
					cout<< "1. Increase Quantity" << endl; // Add existing part
					cout<< "2. Consume Part" <<  endl; // Part gets used
					cout<< "3. Set Location" << endl; // Loc within shop is arbitrary to program
					cout<< "4. Done" << endl;
					getline(cin, pMenu);
					c = stoi(pMenu);

					switch(c) {
						case 1: {
							int amt;
							cout << "How many "<< tmp->partName << "s will being added" << endl;
							getline(cin, input);
							amt = stoi(input);
							tmp->quantity += amt;
							break;
						}
						case 2: {
							tmp->quantity--;
							cout << "Part Consumed" << endl;
							break;
						}
						case 3: {
							cout << "Enter Location" << endl; // e.g Bin4 Drawer 3
							getline(cin, input);
							tmp->location = input;
							break;
						}
						case 4: {
							break;
						}
					}
				}
				cout << endl;
				break;
			}
			case 3: 
			{
				// Search network with similar airframes
				cout << "Enter part number" << endl;
				getline(cin, input);
				int num = stoi(input);
				part *tmp = home->inventory.searchParts(num);
				network.inquiry(num, home->name);
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "Enter part number" << endl;
				getline(cin, input);
				int num = stoi(input);
				part *tmp = home->inventory.searchParts(num);
				if(tmp == NULL) {
					cout << "Part Does not exist" << endl;
					cout << endl;
					break;
				}

				bool chc = false;
				while(chc == false) {
					cout << "Order " << tmp->partName << " for: $";
					cout << tmp->cost << "[y/n]" << endl;
					getline(cin, input);
					if(input=="y"||input=="Y") {
						//Order part fn
						cout << "Part Ordered" << endl;
						break;
					}
					if(input=="n"||input=="N") {
						cout << "Tranaction Cancelled" << endl;
						break;
					}
					else
						continue;
				}
			}
			case 5:
			{
				cout << "GoodBye" << endl;
				break;
			}
		}
	}
	return 0;
}