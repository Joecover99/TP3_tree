#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Graph/Edge.h"
#include "../Graph/Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphTest
{
	TEST_CLASS(GraphTest)
	{
	public:

		/*
		TEST_METHOD(test)
		{
			//Arrange
			//Action
			//Assert
		}
		*/

		TEST_METHOD(EDGE_getCost_retourne_le_prix)
		{
			//Arrange
			const int ANY_COST = 5;
			std::string any_name = "Joe";
			Node* any_node = new Node(any_name);
			Edge edge = Edge(ANY_COST, any_node);

			//Action
			int price = edge.getCost();

			//Assert
			const int EXPECTED_PRICE = 5;
			Assert::AreEqual(price, EXPECTED_PRICE);
		}
		/*
		TEST_METHOD(EDGE_getNeighbor_retourne_le_voisin)
		{
			//Arrange
			const int ANY_COST = 5;
			Node* any_node;
			Edge edge = Edge(ANY_COST, any_node);

			//Action
			Node* neighbor = edge.getNeighbor();

			//Assert
			Assert::AreEqual(neighbor, any_node);
		}
		*/
		//////////////////////////////////////////////////////////

		TEST_METHOD(NODE_getName_retourne_le_nom_du_sommet)
		{
			//Arrange
			std::string any_name = "Albert";
			Node* node = new Node(any_name);

			//Action
			std::string actualName = node->getName();

			//Assert
			Assert::AreEqual(any_name, actualName);
		}

		TEST_METHOD(NODE_addEdge_add_element_to_list)
		{
			//Arrange
			const std::string any_name = "Albert";
			Node* node = new Node(any_name);

			Node* nodeToAdd = new Node(any_name);
			const int any_cost = 5;
			//Action
			node->addEdge(nodeToAdd, any_cost);

			//Assert
			unsigned int actualNumberOfEdges = node->getNumberOfEdges();
			const unsigned int EXPECTED_NUMBER = 1;
			Assert::AreEqual(actualNumberOfEdges, EXPECTED_NUMBER);
		}
		/*
		TEST_METHOD(NODE_addEdge_add_le_sommet_sur_lui_meme_EXCEPTION)
		{
			//Arrange
			const std::string any_name = "Albert";
			Node* node = new Node(any_name);
			bool exceptionCatched = false;

			const int any_cost = 5;
			//Action
			try {
				node->addEdge(node, any_cost);
			}
			catch (...) {
				exceptionCatched = true;
			}

			//Assert
			Assert::IsTrue(exceptionCatched);
		}
		/*
		TEST_METHOD(NODE_addEdge_add_sommet_deux_fois_le_meme_EXCEPTION)
		{
			//Arrange
			const std::string any_name = "Albert";
			Node* node = new Node(any_name);

			Node* nodeToAdd;
			const int any_cost = 5;
			node->addEdge(nodeToAdd, any_cost);

			bool exceptionCatched = false;

			//Action
			try {
				node->addEdge(nodeToAdd, any_cost);
			}
			catch (...) {
				exceptionCatched = true;
			}

			//Assert
			Assert::IsTrue(exceptionCatched);
		}
		*/
	};
}