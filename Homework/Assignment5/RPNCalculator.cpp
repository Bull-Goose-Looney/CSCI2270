#include "RPNCalculator.hpp"

using namespace std;

RPNCalculator::RPNCalculator()
{
	stackHead = NULL;
}

bool RPNCalculator::isEmpty()
{
	if(stackHead == NULL)
		return true;
	else
		return false;
}

void RPNCalculator::push(float num)
{
	Operand *newOp = new Operand;

	// if stack is empty, set head.
	if(isEmpty())
	{
		newOp->number = num;
		stackHead = newOp;
		newOp->next = NULL;
	}
	// add to top of stack
	else {

		Operand *tmp = stackHead; // old head
		newOp->next = tmp; // points to old head
		delete tmp;
		newOp->number = num;
		stackHead = newOp; // Set new head.
	}

}

void RPNCalculator::pop()
{
	// if Stack is not empty delete node.
	if(!isEmpty())
	{
		// If only one thing in stack
		if(stackHead->next==NULL)
		{
			delete stackHead;
			stackHead = NULL;			
		}

		// If multiple things in stack
		else {
			Operand *tmp = stackHead; // store head
			stackHead = stackHead->next; // move head forward.
			delete tmp; // deallocate
		}		
	}
	else
		cout << "Stack empty, cannot pop an item." << endl;
}

Operand* RPNCalculator::peek()
{
	if(!isEmpty())
		return getStackHead();
	else{
		cout << "Stack empty, cannot peek." << endl;
		return NULL;
	}
}

bool RPNCalculator::compute(string symbol)
{
	float num1;
	float num2;
	float product;
	float sum;

	bool valid = false;

	if(isEmpty())
	{
		cout << "err: not enough operands" << endl;
		return valid;
	}

	if(symbol != "+" && symbol != "*")
	{
		cout << "err: invalid operation" << endl;
		return valid;
	}


	if(!isEmpty())
	{
		num1 = stackHead->number;
		pop();

		if(isEmpty())
		{
			cout << "err: not enough operands" << endl;
			push(num1);
			return valid;
		}
		else{
			num2 = stackHead->number;
			valid = true;
			pop();
		}

		if(symbol == "+")
		{
			sum = num1 + num2; 
			push(sum);
		} 
		else {
			product = num1 * num2;
			push(product);
		}

		/*cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl;
		cout << "Sum: " << sum << endl;
		cout << "Product: " << product << endl;
		*/
	}
	return valid;
}


RPNCalculator::~RPNCalculator()
{
	Operand *del = nullptr;
	while(!isEmpty())
	{
		del = stackHead;
		stackHead = stackHead->next;
		delete del;
	}

	stackHead = NULL;
}