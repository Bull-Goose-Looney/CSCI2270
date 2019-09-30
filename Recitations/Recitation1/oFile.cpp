#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  //to write
  //creates instance of ofstream and opens the file
  ofstream oFile("filename.txt");
  //outputs to filename.txt

  oFile << "Inserted this text into filename.txt";

  // Close the file fstream
  oFile.close();

}
