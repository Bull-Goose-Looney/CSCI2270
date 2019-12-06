#include "Parts.hpp"
#include "Shop.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int split (string str, char c, string fill[])
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

void displayMenu() {

	cout<<  "======Main Menu======" << endl;
	cout<< "1. Print the inventory" << endl;
	cout<< "2. Delete a movie" <<  endl;
	cout<< "3. Quit" << endl;

}
 
int main(int argc, char const *argv[]) {
	
	ShopGraph shop;

	string partsList = argv[1];

	ifstream data;
	data.open(partsList);

	string temp[7];
	int partNum;
	string partName;
	string manufacturer;
	float cost;
	string[3] airFrames; // Max: 3 Airframes

	string line;
	if(data.is_open()) {

		while(getline(data, line)) {

			split(line, ',', temp);
			partName = temp[0];
			partNum = stoi(temp[1]);
			manufacturer = temp[2];
			cost = stof(temp[3]);
			airFrames[0] = temp[4];
			airFrames[1] = temp[5];
			airFrames[2] = temp[6];

			
		}
		data.close();
	}

	string input;
	int choice = 0;
	float rate;
	int date;

	while(choice!=3) {
		displayMenu();
		getline(cin, input);
		choice = stoi(input);
		switch(choice) {
			case 1: {
				m.printMovieInventory();
				break;
			}
			case 2: {
				cout << "Enter a movie title: " << endl;
				getline(cin, input);
				m.deleteMovie(input);
				break;
			}
			case 3: {
				cout << "Goodbye!" << endl;
				break;
			}

		}
	}
	return 0;
}