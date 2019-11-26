#pragma once

#include "Edge.h"
#include <string>

#include "LinkedListElement.h"
#include "LinkedList.h"

class Node : public LinkedListElement { //Sommet
public:

	Node(std::string name);

	void addEdge(Node* node, int cost);
	void deleteEdge(std::string name);
	std::string getName();
	unsigned int getNumberOfEdges();
	bool checkIfNeighbor(std::string name);

	~Node();

private:

	std::string name;
	LinkedList* listEdges;

	struct EdgeAlreadyUsed : public std::exception
	{
		//Message d'exception ici au besoin.
	};

	struct NodeNotLinked : public std::exception
	{
		//Message d'exception ici au besoin.
	};
};