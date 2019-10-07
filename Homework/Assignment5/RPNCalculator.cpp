#include "RPNCalculator.hpp"

using namespace std;

RPNCalculator::RPNCalculator()
{
	stackHead = nullptr;
}

bool RPNCalculator::isEmpty()
{
	if stackHead == nullptr
		return true;
	else
		return false;
}

void RPNCalculator::push(num)
{
	Operand *newOp = new Operand;

	if(stackHead == nullptr)
	{
		newOp->number = num;
		stackHead = newOp;
		newOp->next = nullptr;
	}
	else{

		newOp = stackHead;

		while(newOp!=nullptr)
			newOp = newOp->next;

		newOp->next = nullptr;
		newOp->number = num;

	}

}

RPNCalculator::~RPNCalculator()
{
  
}