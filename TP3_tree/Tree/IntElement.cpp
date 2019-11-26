#include "IntElement.h"

IntElement::IntElement(int element)
{
	this->_element = element;
}

int IntElement::getElement() const
{
	return this->_element;
}

bool IntElement::operator==(const TreeElement& element)
{
	if (_element == ((IntElement&)element).getElement()) {
		return true;
	}
	return false;
}

bool IntElement::operator<(const TreeElement& element)
{
	if (_element < ((IntElement&)element).getElement()) {
		return true;
	}
	return false;
}

bool IntElement::operator>(const TreeElement& element)
{
	if (_element > ((IntElement&)element).getElement()) {
		return true;
	}
	return false;
}