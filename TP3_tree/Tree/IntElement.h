#pragma once
#include "TreeElement.h"

class IntElement :
	public TreeElement
{
	public:
		IntElement(int element);
		int getElement() const;

		bool operator==(const TreeElement& element);
		bool operator<(const TreeElement& element);
		bool operator>(const TreeElement& element);

	private:
		int _element;
};