#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  // File Reading
  char str[10];
  // Opens the file for Reading
  // Ensure that filename.txt is present in the same directory

  //as that of the source file
  ifstream iFile("filename.txt");

  //Reads one string from the file
  iFile >> str;

  // outputs the file contents
  cout << str << "\n";

  // Wait for keypress
  cin.get();
  iFile.close();


}
