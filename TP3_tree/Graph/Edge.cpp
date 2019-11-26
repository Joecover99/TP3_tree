#include "Edge.h"

Edge::Edge(int cost, Node* neighbor)
{
	this->cost = cost;
	this->neighbor = neighbor;
}

unsigned int Edge::getCost()
{
	return this->cost;
}

Node* Edge::getNeighbor()
{
	return this->neighbor;
}

Edge::~Edge() {} //Pas de new; desctructeur vide