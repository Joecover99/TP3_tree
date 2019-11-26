#include "Node.h"

Node::Node(std::string name) 
{
	this->name = name;
	this->listEdges = new LinkedList();
}

Node::~Node()
{
}

void Node::addEdge(Node* node, int cost)
{
	if (node == this) throw EdgeAlreadyUsed();

	if (this->listEdges->isEmpty()) {
		Edge* edgeToAdd = new Edge(cost, node);
		this->listEdges->add(*edgeToAdd);
	}
	else {
		Iterator* listToCheck = this->listEdges->getIterator();
			int counter = 0;
			Node* temp = (Node*)&listToCheck->current();
			while (counter < this->listEdges->getNbElements()) {
				if (temp == node) {
					throw EdgeAlreadyUsed();
				}
				temp = (Node*)&listToCheck->previous();
				counter++;
			}
		Edge* edgeToAdd = new Edge(cost, node);
		this->listEdges->add(*edgeToAdd);
	}
	
}

void Node::deleteEdge(std::string name)
{
	Iterator* listToCheck = this->listEdges->getIterator();
	int counter = 0;
	bool actionPerformed = false;
	while (counter <= this->listEdges->getNbElements()) {
		Node* temp = (Node*)&listToCheck->previous();
		if (temp->getName() == name) {
			listToCheck->remove(*temp);
			actionPerformed = true;
			break;
		}
		counter++;
	}
	if (!actionPerformed) {
		throw NodeNotLinked();
	}
}

std::string Node::getName()
{
	return this->name;
}

unsigned int Node::getNumberOfEdges()
{
	Iterator* listToCheck = this->listEdges->getIterator();
	Node* temp = (Node*)&listToCheck->current();

	int counter = 0;
	while (temp != NULL) {
		counter++;
		temp = (Node*)&listToCheck->previous();
	}
	return counter;
}

bool Node::checkIfNeighbor(std::string name)
{
	return false;
	/*
	Iterator* listToCheck = this->listEdges->getIterator();
	int counter = 0;
	Node* temp = (Node*)&listToCheck->current();
	while (counter < this->listEdges->getNbElements()) {
		if (temp->getName() == name) {
			listToCheck->remove(*temp);
			break;
		}
		temp = (Node*)&listToCheck->previous();
		counter++;
	}
	*/
}
