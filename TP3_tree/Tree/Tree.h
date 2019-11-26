#include <stdio.h>
#include <iostream>
#include "TreeElement.h"

#include <exception>

#pragma once

class Tree
{
public:
	Tree();

	void add(TreeElement* element);
	int find(TreeElement* element);
	int sizeOfTree();
	bool isEmpty();
	int depthOfTree();

	~Tree();

private:
	struct Node
	{
		TreeElement* _element;
		Node* _parent;
		Node* _left;
		Node* _right;

		Node(TreeElement* element, Node* parent) {
			_element = element;
			_parent = parent;
			_left = NULL;
			_right = NULL;
		}
	};

	int getDepth(Node* node);

	int sizeOfTree(Node* rootOfTree); //Fonction récursive
	void balance(Node* lastNodeAdded);
	void add(TreeElement* element, Node* node); //Fonction récursive
	int find(TreeElement* element, Node* node); //Fonction récursive
	void remove(Node* node);
	int depthOfTree(Node* node);

	//Fonction pour le balance
	bool isBalance(Node* _root);
	int checkTreeHeight(Node _root);
	void rotateToRight(Node* _parent);
	void rotateToLeft(Node* _parent);
	void doubleRotateToRight();
	void doubleTotateToLeft();
	void setLeft(Node* node);

	Node* _root;

	struct numberAlreadyUsed : public std::exception {
		//Exception pour l'élément déjà existant
	};
};