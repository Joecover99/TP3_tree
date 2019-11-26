#pragma once

#include <string>
#include "LinkedList.h"
#include "Node.h"

class Graph { //Graphe
	
	public :
		
		Graph();
		~Graph();
		void addSommet(std::string name);
		void deleteSommet(std::string name);
		Node* getSommet(std::string name);

		//int getBestCost(); //Points bonus

	private :

		LinkedList* listNodes;

		struct NameAlreadyUsed : public std::exception
		{
			//Message d'exception ici au besoin.
		};
};