#include "MovieTree.hpp"
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

int readFile(string fileName, MovieTree m) {

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

			split(line, ",", temp);
			rank = stoi(temp[0]);
			title = temp[1];
			year = stoi(temp[2]);
			rating = stof(temp[3]);
			m.addMovieNode(rank, title, year, rating);
		}
		data.close();
		return 1;
	}
	else
		return 0;
}

void displayMenu() {

	cout​ << ​ "======Main Menu======"​ << ​ endl​;
	cout​ << "1. Find a movie"​ << ​ endl​;
	cout​ << "2. Query movies"​ << ​ endl​;
	cout​ << "3. Print the inventory"​ << ​ endl​;
	cout​ << "4. Average Rating of movies"​ << ​ endl​;
	cout​ << "5. Find a movie"​ << ​ endl​;

}
 
int main(int argc, char const *argv[]) {
	
	MovieTree m;
	string movieFile = argv[1];
	string docFile = argv[2];

	readFile(movieFile, m);
	
	
}







