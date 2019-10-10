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

// Display for troubleShooting
void ProducerConsumer::display()
{
	for(int i = 0; i < SIZE; i++)
		cout << "Item " << i+1 << ":  " <<  queue[i] << endl;
}


// Checks if queue is empty
bool ProducerConsumer::isEmpty() { if(counter == 0) return true; else return false; }

// Checks of queue is full
bool ProducerConsumer::isFull() { if(counter == 20) return true; else return false; }


void ProducerConsumer::enqueue(string item) {

	if(!isFull()) {

		if(queueEnd == 20) 
			queueEnd = 0;

		queue[queueEnd] = item;
		queueEnd++;
		counter++;

		
	}
	else
		cout << "Queue full, cannot add new item" << endl;

}

void ProducerConsumer::dequeue() {

	if(!isEmpty()) {

		if(queueFront == 20) // Start counter over at 1
			queueFront = 0;

		queue[queueFront] = "";
		queueFront++;
		counter--;
	}
	else
		cout << "Queue empty, cannot dequeue an item" << endl;

}


string ProducerConsumer::peek() {

	if(isEmpty())
	{
		cout << "Queue empty, cannot peek" << endl;
		return "";
	}
	else
		return queue[queueFront];
		
}

int ProducerConsumer::queueSize() {

	return counter; 
}
