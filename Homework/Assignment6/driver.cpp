#include "MovieTree.hpp"
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

	cout <<  "======Main Menu======" << endl;
	cout<< "1. Find a movie" <<  endl;
	cout << "2. Query movies" <<  endl;
	cout<< "3. Print the inventory" << endl;
	cout << "4. Average Rating of movies" <<  endl;
	cout << "5. Quit" << endl;

}
 
int main(int argc, char const *argv[]) {
	
	MovieTree m;
	string movieFile = argv[1];

	ifstream data;
	data.open(movieFile);

	string temp[4];
	int rank;
	string title;
	int year;
	float rating;

	string line;
	if(data.is_open()) {

		while(getline(data, line)) {

			split(line, ',', temp);
			rank = stoi(temp[0]);
			title = temp[1];
			year = stoi(temp[2]);
			rating = stof(temp[3]);
			m.addMovieNode(rank, title, year, rating);
		}
		data.close();
	}

	string input;
	int choice = 0;
	float rate;
	int date;

	while(choice!=5) {
		displayMenu();
		getline(cin, input);
		choice = stoi(input);
		switch(choice) {
			case 1: {
				cout << "Enter title:" << endl;
				getline(cin, input);
				m.findMovie(input);
				break;
			}
			case 2: {
				cout << "Enter minimum rating:" << endl;
				getline(cin, input);
				rate = stof(input);

				cout << "Enter minimum year:" << endl;
				getline(cin, input);
				date = stoi(input);

				m.queryMovies(rate, date);
				break;
			}
			case 3: {
				m.printMovieInventory();
				break;
			}
			case 4: {
				m.averageRating();
				break;
			}
			case 5: {
				cout << "Goodbye!" << endl;
				break;
			}
		}
	}
	return 0;
}