#include "LinkedList.h"

////////////////////// LIST \\\\\\\\\\\\\\\\\\\\

LinkedList::LinkedList()
{
	this->_nbElements = 0;
	this->_last = NULL;
}

void LinkedList::add(LinkedListElement& element)
{
	Cell* temp;

	if (isEmpty()) {
		temp = new Cell(&element, NULL, NULL);
		this->_last = temp;
		this->_last->_next = this->_last;
		this->_last->_previous = this->_last;
	}
	else {
		temp = new Cell(&element, this->_last, NULL); //Pour éviter la circularité
		this->_last->_next->_previous = temp;
		this->_last->_next = temp;
		this->_last = temp;
	}
	this->_nbElements++;
}

int LinkedList::getNbElements() const
{
	return this->_nbElements;
}

bool LinkedList::isEmpty() const
{
	if (this->_nbElements == 0) {
		return true;
	}
	else { return false; };
}

void LinkedList::clear()
{
	while (this->_nbElements != 0) {
		Cell* temp = this->_last;
		this->_last = this->_last->_previous;
		delete temp;
		this->_nbElements--;
	}
}

Iterator* LinkedList::getIterator()
{
	if (this->isEmpty()) throw new EmptyListException;
	return new ListIterator(this, this->_last);
}

LinkedList::~LinkedList()
{
	this->clear();
}

////////////////////// ITERATOR \\\\\\\\\\\\\\\\\\\\

LinkedList::ListIterator::ListIterator(LinkedList* list, LinkedList::Cell* current)
{
	this->_list = list;
	this->_current = current;
}

void LinkedList::ListIterator::add(LinkedListElement& element)
{
	this->_list->add(element);
	this->_current = this->_list->_last;
}

void LinkedList::ListIterator::remove(LinkedListElement& element)
{
	if (this->_list->isEmpty()) throw new EmptyListException;
	Cell* temp = this->_current;
	while (temp != NULL) {
		if (temp->_element == &element) {
			this->_current->_previous->_next = this->_current->_next;
			this->_current->_next->_previous = this->_current->_previous;
			this->_current = this->_current->_next;
			delete temp;
			this->_list->_nbElements--;
			break; //L'élément a été trouvé on peut passer à autre chose
		}
		else {
			temp = temp->_previous;
		}
	}
}

LinkedListElement& LinkedList::ListIterator::current()
{
	LinkedListElement& element = *this->_current->_element;

	return element;
}

LinkedListElement& LinkedList::ListIterator::previous()
{
	LinkedListElement& element = *this->_current->_previous->_element;
	this->_current = this->_current->_previous;

	return element;
}

LinkedListElement& LinkedList::ListIterator::next()
{
	LinkedListElement& element = *this->_current->_next->_element;
	this->_current = this->_current->_next;

	return element;
}

LinkedList::ListIterator::~ListIterator()
{
}