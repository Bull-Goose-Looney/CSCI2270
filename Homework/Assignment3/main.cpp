/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"

// you may include more libraries as needed

// declarations for main helper-functions

void displayMenu();
int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    string choice;
    string input;

    // convert the `choice` to an integer
    int menuChoice = 0;

    while(menuChoice != 8)
    {
        displayMenu();
        getline(cin, choice);
        menuChoice = stoi(choice);
        switch (menuChoice)
        {

            case 1:
            {
                CountryNet.loadDefaultSetup();
                CountryNet.printPath();
                cout << endl;
                break;
            }


            case 2:
            {
                CountryNet.printPath();
                cout << endl;
                break;
            }

            case 3:
            {
                string newC;
                cout << "Enter a new country name: " << endl;
                getline(cin, newC);
                toupper(newC[0]);

                string prevC;
                cout << "Enter the previous country name (or First): " << endl;
                getline(cin, prevC);
                toupper(prevC[0]);

                Country *tmp = new Country;

                if(prevC == "First")
                {
                    CountryNet.insertCountry(NULL, newC);
                    CountryNet.printPath();
                    cout << endl;
                    break;
                }

                tmp = CountryNet.searchNetwork(prevC);
                if(tmp == NULL)
                {
                    while(tmp == NULL)
                    {
                        cout << "INVALID(previous country name)...Please enter "
                        << "a VALID previous country name!";

                        getline(cin, prevC);
                        toupper(prevC[0]);
                        cout << endl;

                        tmp = CountryNet.searchNetwork(prevC);
                    }
                    CountryNet.insertCountry(tmp, newC);
                }
                else
                {
                    CountryNet.insertCountry(tmp, newC);
                }
                CountryNet.printPath();
                cout << endl;
                break;
            }

            case 4: // Delete Country.
            {
                cout << "Enter a country name: " << endl;
                getline(cin, input);

                if(CountryNet.searchNetwork(input) == NULL)
                {
                    break;
                }
                else {
                    CountryNet.deleteCountry(input);
                }

                CountryNet.printPath();
                cout << endl;
                break;

            }

            case 5: // Reverse Network.
            {
                CountryNet.reverseEntireNetwork();
                CountryNet.printPath();
                cout << endl;
                break;
            }

            case 6: // Rotate Network
            {
                cout << "Enter the count of values to be rotated: " << endl;
                getline(cin, input);
                int in = stoi(input);
                CountryNet.rotateNetwork(in);
                CountryNet.printPath();
                cout << endl;
                break;
            }

            case 7: // Clear network
            {
                cout << "Network before deletion" << endl;
                CountryNet.printPath();
                cout << endl;
                CountryNet.deleteEntireNetwork();
                cout << "Network after deletion" << endl;
                CountryNet.printPath();
                cout << endl;
                break;
            }

            case 8:
            {
                cout << "Quitting...";
                cout << " cleaning up path: " << endl;
                CountryNet.printPath();
                cout << endl;
                CountryNet.deleteEntireNetwork();
                cout << endl;
                cout << "Path cleaned" << endl << "Goodbye!" << endl;
                cout << endl;
                break;
            }
        }
    }
    return 0;
}

/*
 * Purpose; displays a menu with options
 */
 void displayMenu()
 {
     cout << "Select a numerical option:" << endl;
     cout << "+=====Main Menu=========+" << endl;
     cout << " 1. Build Network " << endl;
     cout << " 2. Print Network Path " << endl;
     cout << " 3. Add Country " << endl;
     cout << " 4. Delete Country " << endl;
     cout << " 5. Reverse Network" << endl;
     cout << " 6. Rotate Network" << endl;
     cout << " 7. Clear Network " << endl;
     cout << " 8. Quit " << endl;
     cout << "+-----------------------+" << endl;
     cout << "#> ";
 }
