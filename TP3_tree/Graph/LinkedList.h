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

	LinkedList(const LinkedList&); //copieur d�sactiv� puisque dans la partie priv�e
	const LinkedList& operator=(const LinkedList&); //affectateur d�sactiv� puisque dans la partie priv�e

	//Attributs de la classe CircularDoubleLinkedList
	int _nbElements;
	Cell* _last;

	//Rappel d'un �l�ment discut� en classe: si la cellule point�e par _last est supprim�e par l'it�rateur,
	//il faut que _last soit r�ajust� pour pointer sur la nouvelle derni�re cellule, qui doit �tre la cellule positionn�e avant la cellule supprim�e.

	struct EmptyListException : public std::exception
	{
		//Message d'exception ici au besoin.
	};
};