#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

// Constructor
ProducerConsumer::ProducerConsumer() {

	queueFront = 0; 
	queueEnd = 0;

	for(int i = 0; i < SIZE - 1; i++)
	{
		queue[i] = "";
	}

}


// Checks if queue is empty
bool ProducerConsumer::isEmpty() { if(counter == 0) return true; else return false; }

// Checks of queue is full
bool ProducerConsumer::isFull() { if(counter == SIZE) return true; else return false; }


void ProducerConsumer::enqueue(string item) {

	if(isFull())
	{
		cout << "Queue full, cannot add new item" << endl;
	}
	else{

		queue[queueEnd] = item;
		counter++;
		queueEnd++;
	}

}

void ProducerConsumer::dequeue() {

	if(isEmpty())
		cout << "Queue empty, cannot dequeue an item" << endl;
	else {
		
		if(queueFront != 0)
		{
			queue[queueFront - 1] = queue[queueFront];
			queue[queueFront] = "";
			counter--;
			queueEnd--;			
		}
		

	}

}


string ProducerConsumer::peek() {

	if(isEmpty())
	{
		cout << "Queue empty, cannot peek" << endl;
		return "";
	}
	else
		cout << queue[queueFront] << endl;
		return queue[queueFront];
		
}

void ProducerConsumer::display()
{
	for(int i = 0; i < SIZE; i++)
		cout << "Item " << i+1 << ":  " <<  queue[i] << endl;
}

int ProducerConsumer::queueSize() { return counter; }
