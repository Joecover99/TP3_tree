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

void Graph::addSommet(std::string name, Node* node)
{
	Iterator* iterator = this->listNodes->getIterator();
	int counter = 0;

	Node* temp = (Node * &)iterator->current();
	while (counter < this->listNodes->getNbElements())
	{
		if (temp->getName() == name)
		{
			throw NameAlreadyUsed();
		}
		Node temp = (Node&)iterator->previous();
		counter++;
	}
	Node* nodeToAdd = new Node(name);
	this->listNodes->add(*nodeToAdd);
}

void Graph::deleteSommet(std::string name)
{
	Iterator* iterator = this->listNodes->getIterator();
	int counter = this->listNodes->getNbElements();
	while (counter < this->listNodes->getNbElements()) {
		Node* temp = (Node*)& iterator->previous();
		if (temp->getName() == name) {
			iterator->remove(*temp);
			break;
		}
		if (counter == (this->listNodes->getNbElements() - 1))
		{
			break;
		}
		counter--;
	}
}

Node* Graph::getSommet(std::string name)
{
	Iterator* iterator = this->listNodes->getIterator();
	Node* node = (Node*)& iterator->current();

	return node;
}