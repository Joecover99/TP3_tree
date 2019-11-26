#include "Graph.h"
#include "LinkedList.h"
#include "LinkedListElement.h"

Graph::Graph()
{
	this->listNodes = NULL;
}

Graph::~Graph()
{
}

void Graph::addSommet(std::string name,Node* node)
{
	
	if(name == this->listNodes->getIterator)
	{
		 throw NameAlreadyUsed();
	}
	if(this->listNodes->isEmpty())
	{
		Edge* sommetToAdd = new Edge(name, node);
		this->listNodes->add(sommetToAdd);


	}
	if (node == this) throw sommetToAdd();
/*
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
	}*/
}

void Graph::deleteSommet(std::string name)
{

}

Node* Graph::getSommet(std::string name)
{
	return NULL;
}
