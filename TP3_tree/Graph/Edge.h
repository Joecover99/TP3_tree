#pragma once

#include "LinkedListElement.h"

class Node;
#include "Node.h"

class Edge : public LinkedListElement { //Ar�te

	public :

		Edge(int cost, Node* neighbor);

		unsigned int getCost();
		Node* getNeighbor();

		~Edge();

	private :

		unsigned int cost;
		Node* neighbor;
};