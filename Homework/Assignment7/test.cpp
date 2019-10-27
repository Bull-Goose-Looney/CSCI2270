#include "MovieTree.hpp"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
 
int main() {

	MovieTree m;
	m.addMovie(5,"Enron", 1969, 3.3);
	m.addMovie(5,"Dogtown", 1969, 3.3);
	m.addMovie(5,"Dancin'", 1969, 3.3);
	m.addMovie(5,"Bowling for Columbine", 1969, 3.3);
	m.addMovie(5,"Taxi to the ds", 1969, 3.3);
	m.addMovie(5,"Man on wire", 1969, 3.3);
	m.addMovie(5,"Hands on Hardboy", 1969, 3.3);
	m.addMovie(5,"Jiro", 1969, 3.3);
	m.addMovie(5,"Down from the mountain", 1969, 3.3);
	m.printMovieInventory();
	cout << endl;

	m.deleteMovie("Enron");
	cout << endl << "Deleted Enron" << endl << endl;
	m.printMovieInventory();
}