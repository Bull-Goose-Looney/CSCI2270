// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    node *crl=table[index];
    while(crl!=NULL) {
        if(crl->key == key) {
            return crl;
        }
        crl = crl->next;
    }
    return NULL;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        int insert = hashFunction(key);
        node *n = createNode(key, table[insert]);
        return true;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    node *crl = new node;
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        crl = table[i];
        while(crl!=NULL) {
            cout << "hi";
            cout << crl->key << endl;
            crl = crl->next;
        }
    }
 }
