/****************************************************************/
/*                    Menu based program		                */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer prod;
	// Variables should go outside of switch.
	string choice;
    string input;
    int numItems;

    // convert the `choice` to an integer
    int menuChoice = 0;

    while(menuChoice != 3)
    {
        menu();
        getline(cin, choice);
        menuChoice = stoi(choice);

        switch (menuChoice)
        {

            case 1:
            {
            	cout << "Enter the number of items to be produced:" << endl;
            	getline(cin, input);
            	numItems = stoi(input);

            	for(int i = 0; i < numItems; i++) {
            		cout << "Item" << i+1 << ":" << endl;
            		getline(cin, input);
            		prod.enqueue(input);
            	}

                break;
            }


            case 2:
            {
            	cout << "Enter the number of items to be consumed:" << endl;
            	getline(cin, input);
            	numItems = stoi(input);

            	if(numItems >= prod.queueSize())
            		numItems = prod.queueSize();

            		for(int i=0;i<numItems;i++) {
            			cout << "Consumed: " << prod.peek() << endl;
            			prod.dequeue();
            		}

            	if(prod.queueSize() == 0)
					cout << "No more items to consume from queue" << endl;

                break;
            }

            case 3:
            {
            	cout << "Number of items in the queue:" << prod.queueSize();
                cout << endl;
                break;
            }
        }
    }

    return 0;
}
