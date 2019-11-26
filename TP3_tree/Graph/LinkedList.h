#pragma once
#include <iostream>

#include "Iterator.h"

#include "LinkedListElement.h"

class LinkedList
{
public:
	LinkedList();

	void add(LinkedListElement& element);
	int getNbElements() const;
	bool isEmpty() const;
	void clear();
	Iterator* getIterator();

	~LinkedList();

private:

	struct Cell
	{
		LinkedListElement* _element;

		Cell* _previous;
		Cell* _next;

		Cell(LinkedListElement* element, Cell* previous, Cell* next)
		{
			_element = element;
			_previous = previous;
			_next = next;
		};
		~Cell() {};
	};

	class ListIterator :
		public Iterator
	{
	public:
		ListIterator(LinkedList* list, LinkedList::Cell* current);

		void add(LinkedListElement& element);
		void remove(LinkedListElement& element);
		LinkedListElement& previous();
		LinkedListElement& next();
		LinkedListElement& current();

		~ListIterator();

	private:
		LinkedList::Cell* _current;
		LinkedList* _list;
	};

	LinkedList(const LinkedList&); //copieur désactivé puisque dans la partie privée
	const LinkedList& operator=(const LinkedList&); //affectateur désactivé puisque dans la partie privée

	//Attributs de la classe CircularDoubleLinkedList
	int _nbElements;
	Cell* _last;

	//Rappel d'un élément discuté en classe: si la cellule pointée par _last est supprimée par l'itérateur,
	//il faut que _last soit réajusté pour pointer sur la nouvelle dernière cellule, qui doit être la cellule positionnée avant la cellule supprimée.

	struct EmptyListException : public std::exception
	{
		//Message d'exception ici au besoin.
	};
};