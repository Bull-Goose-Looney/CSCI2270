#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

int main() {

	ProducerConsumer test;

	cout << endl;
	cout << "--------------------" << endl;
	cout << "Counter = " << test.queueSize() << endl;
	cout << "queueFront = " << test.getQueueFront() << endl;
	cout << "queueEnd = " << test.getQueueEnd() << endl;
	cout << "--------------------" << endl;

	cout << endl << "ENQUEUE 20" << endl << "-----------" << endl;
	for(int i = 0; i < 20; i++) {

		test.enqueue("o");

	}

	test.display();
	cout << endl;
	cout << "--------------------" << endl;
	cout << "Counter = " << test.queueSize() << endl;
	cout << "queueFront = " << test.getQueueFront() << endl;
	cout << "queueEnd = " << test.getQueueEnd() << endl;
	cout << "--------------------" << endl;

	cout << endl << "DEQUEUE 10" << endl << "-----------" << endl;
	for(int i = 0; i < 10; i++) {

		test.dequeue();
	}

	test.display();

	cout << endl;
	cout << "--------------------" << endl;
	cout << "Counter = " << test.queueSize() << endl;
	cout << "queueFront = " << test.getQueueFront() << endl;
	cout << "queueEnd = " << test.getQueueEnd() << endl;
	cout << "--------------------" << endl;


	cout << endl << "ENQUEUE 10" << endl << "-----------" << endl;
	for(int i = 0; i < 10; i++) {

		test.enqueue("x");
	}


	test.display();

	cout << endl;
	cout << "--------------------" << endl;
	cout << "Counter = " << test.queueSize() << endl;
	cout << "queueFront = " << test.getQueueFront() << endl;
	cout << "queueEnd = " << test.getQueueEnd() << endl;
	cout << "--------------------" << endl;


	cout << endl << "DEQUEUE 20" << endl << "-----------" << endl;
	for(int i = 0; i < 20; i++) {

		test.dequeue();
	}

	test.display();

	cout << endl;
	cout << "--------------------" << endl;
	cout << "Counter = " << test.queueSize() << endl;
	cout << "queueFront = " << test.getQueueFront() << endl;
	cout << "queueEnd = " << test.getQueueEnd() << endl;
	cout << "--------------------" << endl;

	return 0;	
}

