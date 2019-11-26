#pragma once
#include "Stdio.h"

class Stack
{
public:
	//Inserts element at the top of the stack. Postconditions : nbElements will be incremented by 1.
	virtual void push(int& element) = 0;

	//Removes the element at the top of the stack. Precondition: nbElements > 0. Postcondition: nbElements will be decremented by 1.
	virtual void pop() = 0;

	//Returns a mutable reference to the element at the top of the stack.Precondition: nbElements > 0.
	virtual int& top() const = 0;

	//Returns true if the stack contains no elements, and false otherwise.
	virtual bool isEmpty() const = 0;

	//Returns the number of elements in the stack.
	virtual int size() const = 0;
};

