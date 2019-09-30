#include "CountryNetwork.hpp"
#include <iostream>

int main()
{
    CountryNetwork a;
    a.loadDefaultSetup();
    a.printPath();
    a.reverseEntireNetwork();
    a.printPath();
    return 0;
}
