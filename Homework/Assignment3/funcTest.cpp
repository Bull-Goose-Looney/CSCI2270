#include <iostream>
#include "CountryNetwork.hpp"
#include "CountryNetwork.cpp"
using namespace std;

int main()
{
    CountryNetwork CountryNet;
    Country *test = new Country;
    string name = "UUUUU";

    insertCountry(test, name);
}
