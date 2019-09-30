#include "CountryNetwork.hpp"
#include <cstring>

using namespace std;

/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/



CountryNetwork::CountryNetwork()
{
    head = nullptr;
}

//===================(Helper Functions)=====================

bool CountryNetwork::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }


}

void CountryNetwork::deleteCountry(string countryName)
{
    Country *prev = head;
    Country *pres = prev -> next;
    bool found = false;

    if(head -> name == countryName)
    {
        found = true;
        prev = head;
        head = head -> next;
        delete prev;
    }

    while(pres != NULL && found == false)
    {
        if(pres -> name == countryName)
        {
            prev -> next = pres -> next;
            prev = prev -> next;
            delete pres;
            found = true;
            break;
        }
        pres = pres -> next;
        prev = prev -> next;
    }

    if(found == false)
    {
        cout << "Country does not exist." << endl;
    }
}

 // Makes linked list with 6 countries
 void CountryNetwork::loadDefaultSetup()
 {
     /* add clearing functionality */
     // List of names and temp Country node;
     string names[6] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
     Country *temp = new Country;

     // Add head (USA)
     Country *prev = new Country;
     insertCountry(prev, names[0]);

     int ctr = 1;
     while(ctr < 6)
     {
         // set temp = to node with previous name
         temp = searchNetwork(names[ctr - 1]);
         // Insert temp with new name
         insertCountry(temp, names[ctr]);
         ctr++;
     }
 }

// Inserts NEW country node after passed node.
// Prints added countries.
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    Country *newCountry = new Country;
    newCountry -> name = countryName;
    bool inserted = false;

    // If inserting into beginnig of list
    if(previous == NULL && head != NULL)
    {
        Country *temp = head;

        previous = newCountry;
        previous -> next = head;
        head = newCountry;
        inserted = true;

        cout << "adding: " << countryName << " (HEAD)" << endl;


    }

    // If First Node
    if(head == NULL)
    {
        head = newCountry;
        newCountry -> next = nullptr;
        inserted = true;

        cout << "adding: " << countryName << " (HEAD)" << endl;

    }

    // If inserting at middle or end of list
    else
    {
        // End of list
        if(previous -> next == NULL && inserted == false)
        {
            previous -> next = newCountry;
            newCountry -> next = nullptr;
            inserted = true;
            cout << "adding: " << countryName << " (prev: " << previous -> name << ")" << endl;

        }

        // Middle
        else if(inserted == false)
        {
            Country *temp = new Country;

            newCountry -> next = previous -> next;
            previous -> next = newCountry;
            cout << "adding: " << countryName << " (prev: " << previous -> name << ")" << endl;
        }
    }
}

// Searches for passed Country name and returns the node with that name
Country* CountryNetwork::searchNetwork(string countryName)
{
    bool found = false;
    Country *temp = new Country;
    Country *notFound = NULL;

    temp = head;

    while(temp != NULL)
    {
        if(temp -> name == countryName)
        {
            found = true;
            return temp;
        }

        temp = temp -> next;
    }

    if(found == false)
    {
        return notFound;
    }

    return temp;

}

void CountryNetwork::deleteEntireNetwork()
{
    Country *prev = head;
    Country *pres = head;

    while(pres != NULL)
    {
        cout << "deleting: " << prev -> name << endl;
        pres = pres -> next;
        delete prev;
        prev = pres;
        if(pres == NULL)
        {
            cout << "Deleted network" << endl;
        }
    }

    head = NULL;

}

void CountryNetwork :: rotateNetwork(int n)
{
    int nodeCtr = 1;
    bool empty = isEmpty();
    bool nBad = false;

    // Make sure n is not too big
    if(empty == false)
    {
        Country *counter = head;
        while(counter != NULL)
        {
          counter = counter  -> next;
          nodeCtr++;
        }
    }

    if(n >= nodeCtr || n <= 1 || empty == true)
    {
      nBad = true;
    }

    //cout << empty << " " << nodeCtr << " " << n << endl;

    if(nBad == false)
    {
      Country *last = head;
      Country *pres = head;
      Country *temp = head -> next;

      for(int i = 0; i < n; i++)
      {

        // Make last = to last node.
        while(last -> next != NULL)
        {
          last = last -> next;
        }

        // Reconnect list.
        last -> next = pres;
        pres -> next = NULL;

        // Set new head
        head = temp;
        pres = head;
        last = head;
        temp = head -> next;

          if(i == n - 1)
          {
            cout << "Rotate Complete" << endl;
          }
      }
    }

    if(empty == true)
    {
      cout << "Linked List is Empty" << endl;
    }

    if(nBad == true && empty == false)
    {
      cout << "Rotate not possible" << endl;
    }
}

void CountryNetwork::reverseEntireNetwork()
{

  if(isEmpty() == false)
  {
      // Find the number of Nodes for main loop.
      Country *ctr = head;
      int numNodes = 0;

      while(ctr->next!=NULL)
      {
          ctr=ctr->next;
          numNodes++;
      }

      Country *temp = head;
      Country *pres = nullptr;
      Country *loop = nullptr;

      // Stores last node and the node before it.
      Country *getLast = nullptr;
      Country *prev = nullptr;

      int loopStop = 0;
      while(loopStop != numNodes)
      {
        // Find last Node and the node before that.
        getLast = head;
        prev = head;
        while(getLast->next != NULL)
        {
            prev = getLast;
            getLast = getLast -> next;
        }

        //On first loop, set last node = head;
        if(loopStop == 0)
        {
            head = getLast; // Last node is new head.
            getLast->next = temp; // have newHead point to oldHead.
            temp = head; // Temp is now newHead.
            prev->next = NULL; // set newLast -> next to null. (end of list)
            loopStop++;
            continue; // Start over to get new last node.
        }

        /* getLast = last node. put it after Temp. */
        //-------------------------------------------

        getLast->next = temp->next; // getLast->next should equal old temp->next
        temp->next = getLast; // connect list.
        temp = temp->next; // Track next pos.
        prev->next = NULL; // set newLast -> next to null. (end of list)

        loopStop++;
      }
  }
}

// Adds passed message to each node from head up to reciever
// Increments message counter.
void CountryNetwork::transmitMsg(string receiver, string message)
{
    Country *temp = head;
    bool found = false;


    if(head == NULL)
    {
        cout << "Empty List" << endl;
    }
    else
    {
        if(searchNetwork(receiver) != NULL)
        {
            while(temp -> name != receiver && temp -> next != NULL)
            {
                temp -> message = message;
                temp -> numberMessages++;

                cout << temp -> name << " [# messages received: " << temp ->
                numberMessages << "] received: " << temp -> message << endl;

                temp = temp -> next;
            }

            if(temp -> name == receiver)
            {
                found = true;
                temp -> message = message;
                temp -> numberMessages++;

                cout << temp -> name << " [# messages received: " << temp ->
                numberMessages << "] received: " << temp -> message << endl;
            }
        }


        if(found == false)
        {
            cout << "Country not found" << endl;
        }
    }
}

// Prints each name from linked list
void CountryNetwork::printPath()
{
    Country *temp = head;
    cout << "== CURRENT PATH ==" << endl;

    if(temp == NULL)
    {
        cout << "nothing in path";
    }
    else
    {

        while(temp != NULL)
        {
            cout << temp -> name << " -> ";
            temp = temp -> next;
            if(temp == NULL)
                cout << "NULL";
        }
    }
    cout << endl << "===";
}
