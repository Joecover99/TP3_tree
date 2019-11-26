#pragma once

class TreeElement {
public:
	virtual bool operator==(const TreeElement& element) = 0;
	virtual bool operator<(const TreeElement& element) = 0;
	virtual bool operator>(const TreeElement& element) = 0;

protected:
	TreeElement() {};
};