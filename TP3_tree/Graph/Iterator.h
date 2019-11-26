#pragma once
#include "LinkedListElement.h"
class Iterator {
public:

	//Inserts the specified element into the list after the current one. 
	//The inserted element becomes the new current one.
	virtual void add(LinkedListElement& element) = 0; //Throws : EmptyListException - if the list has no element (iterator cannot add in a empty list).

	//Removes from the list the current element.
	//The current one will be the next one.
	virtual void remove(LinkedListElement& element) = 0; //Throws : EmptyListException - if the list has no element (iterator cannot remove from an empty list).

	//Returns the previous element in the list and moves the cursor position backwards.This method may be called repeatedly to iterate through the list backwards, 
	//or intermixed with calls to next() to go back and forth. (Note that alternating calls to next and previous will return the same element repeatedly.)
	virtual LinkedListElement& previous() = 0;

	//Returns the next element in the list and advances the cursor position. This method may be called repeatedly to iterate through the list, 
	//or intermixed with calls to previous() to go back and forth. (Note that alternating calls to next and previous will return the same element repeatedly.)
	virtual LinkedListElement& next() = 0;

	virtual LinkedListElement& current() = 0;
};
