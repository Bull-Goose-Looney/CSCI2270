#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n)
{
    Node *prev = head;
    Node *pres = prev->next;
    int nCtr = 0;
    int target = 0;
    bool found = false;

    // If n isnt valid.
    if(n <= 0)
    {
        found = true;
        cout << "bad n" << endl;
    }
    // If LL is not empty.
    if(head != NULL && found == false)
    {
        // Get size of LL
        while(prev->next != NULL)
        {
            prev = prev -> next;
            nCtr++;
        }
        if(nCtr >= n)
        {
            found = true;
        }

        target = nCtr - n; // target will be the number of the target node.

        // traverse to target node.
        prev = head;
        for(int i = 0; i <= target; i++)
        {
            prev = prev->next;
            pres = pres -> next;
        }

        prev->next = pres->next;
        prev = pres->next;
        delete pres;

    }
}

