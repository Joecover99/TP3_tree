#include "Tree.h"
#include <stdexcept>

Tree::Tree() {
	this->_root = NULL;
}

Tree::~Tree() {
	remove(this->_root);
}

void Tree::remove(Node* node) {
	if (node != NULL)
	{
		remove(node->_left);
		remove(node->_right);
		delete node;
	}
}

void Tree::add(TreeElement* element) {
	if (this->_root == NULL) {
		this->_root = new Node(element, NULL); //Arbre vide donc node devient la racineù
	} 
	else {
		if (find(element) != -1) throw new numberAlreadyUsed; //!= -1 car s'il retourne -1 ca veut dire qu'il n'est pas présent
		add(element, this->_root);
	}
}

//Private récursive
void Tree::add(TreeElement* element, Node* node) {
	if (*element < *(node->_element))
	{
		if (node->_left == NULL) {
			Node* newNode = new Node(element, node);
			node->_left = newNode;
		}
		else {
			add(element, node->_left);
		}
	}
	else {
		if (node->_right == NULL) {
			Node* newNode = new Node(element, node);
			node->_right = newNode;
		}
		else {
			add(element, node->_right);
		}
	}
}

bool Tree::isEmpty() {
	bool isEmpty = true;
	if (this->_root != NULL) { isEmpty = false; }
	return isEmpty;
}

bool Tree::isBalance(Node* _root) {
	if (_root == NULL) {
		return true;
	}
	return false;
}
/*
int checkTreeHeight(Node _root)
{
	if (_root == NULL) return 0; // Height of 0.

	// Check if left is balanaced
	int leftChildHeight = checkTreeHeight(_root.left);
	if (leftChildHeight == -1) return -1; // Not Balanced

	// Check if right is balanaced
	int rightChildHeight = checkTreeHeight(_root.right);
	if (rightChildHeight == -1) return -1; // Not Balanced

	// Check if current node is balanced
	int heightDifference = leftChildHeight - rightChildHeight;

	if (Tree(heightDifference) > 1)
		return -1; // not balanaced
	else
		return Math.max(leftChildHeight, rightChildHeight) + 1; // Return Height
		*/
void Tree::rotateToLeft(Node *_parent) {
	Node *temp;
	temp = _parent->_left;
	_parent->_left = temp->_right;
	temp->_right = _parent;
}

void Tree::rotateToRight(Node *_parent) {
	Node *temp;
	temp = _parent->_right;
	_parent->_right = temp->_left;
	temp->_left = _parent;
}



void Tree::balance(Node* lastNodeAdded) 
{
	if(!isBalance){
		
	}
	/*
	Node* nodeToCheckIfBalanced = lastNodeAdded->_parent->_parent;
	Node* parent = lastNodeAdded->_parent;

	if (nodeToCheckIfBalanced->_left == NULL) {
		
	}
	if (nodeToCheckIfBalanced->_right == NULL) {
		
	}
	*/
}

int Tree::find(TreeElement* element) {
	if (isEmpty()) throw new std::invalid_argument("Liste est vide");
	return find(element, this->_root);
}

//Private recursif
int Tree::find(TreeElement* element, Node* node) {
	if (node != NULL) {
		if (*element == *(node->_element)) {
			return getDepth(node);
		}
		else if (*element < *(node->_element)) {
			find(element, node->_left);
		}
		else if (*element > *(node->_element)) {
			find(element, node->_right);
		}
	}
	else {
		return -1;
	}
}

//Private
int Tree::getDepth(Node* node) { //Trouver la profondeur d'une node
	int depth = 0;
	Node* temp = node;

	while (temp != NULL) {
		depth++;
		temp = temp->_parent;
	}
	return depth;
}

int Tree::sizeOfTree() {
	return sizeOfTree(this->_root);
}

//Private recursif
int Tree::sizeOfTree(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		int size = 1;
		size += sizeOfTree(node->_right);
		size += sizeOfTree(node->_left);
		return size;
	}
}

int Tree::depthOfTree() {
	return depthOfTree(this->_root);
}

int Tree::depthOfTree(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		int left = 1;
		int right = 1;
		left += depthOfTree(node->_left);
		right += depthOfTree(node->_right);

		//Voir lequel est le plus grand
		if (left > right) {
			return left;
		}
		else {
			return right;
		}	
	}
}
/*
void Tree::rotateToRight(Node* node) {
	Node* left = node->_left;
	node->setLeft(left_tree->getRight());
	left_tree->setRight(subRoot);
	subRoot = left_tree;
}

void Tree::setLeft(Node* node) {

}
*/
