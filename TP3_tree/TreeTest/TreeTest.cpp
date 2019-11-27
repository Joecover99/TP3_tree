#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Tree/Tree.h"
#include "../Tree/TreeElement.h"
#include "../Tree/IntElement.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TreeTest)
	{
	public:
		TEST_METHOD(isEmpty_retourne_true_quand_larbre_est_vide)
		{
			//Arrange
			Tree tree; //Teste le constructeur

			//Action
			bool isEmpty = tree.isEmpty(); //Teste isEmpty

			//Assert
			Assert::IsTrue(isEmpty);
		}

		TEST_METHOD(isEmpty_retourne_false_quand_larbre_nest_pas_vide)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number); //Teste add

			//Action
			bool isEmpty = tree.isEmpty(); //Teste isEmpty

			//Assert
			Assert::IsFalse(isEmpty);
		}

		TEST_METHOD(sizeOfTree_retourne_0_quand_larbre_est_vide)
		{
			//Arrange
			Tree tree;

			//Action
			int size = tree.sizeOfTree(); //Teste sizeOfTree

			//Assert
			const int EXPECTED_SIZE = 0;
			Assert::AreEqual(EXPECTED_SIZE, size);
		}

		TEST_METHOD(sizeOfTree_retourne_1_quand_seulement_un_element_est_present)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number); //Teste add

			//Action
			int size = tree.sizeOfTree(); //Teste sizeOfTree

			//Assert
			const int EXPECTED_SIZE = 1;
			Assert::AreEqual(EXPECTED_SIZE, size);
		}

		TEST_METHOD(sizeOfTree_retourne_5_quand_seulement_plusieurs_elements_sont_presents)
		{
			//Arrange
			Tree tree;
			IntElement any_number(50);
			IntElement any_number2(25);
			IntElement any_number3(75);
			IntElement any_number4(1);
			IntElement any_number5(100);

			tree.add(&any_number); //Teste add
			tree.add(&any_number2); //Teste add
			tree.add(&any_number3); //Teste add
			tree.add(&any_number4); //Teste add
			tree.add(&any_number5); //Teste add

			//Action
			int size = tree.sizeOfTree(); //Teste sizeOfTree

			//Assert
			const int EXPECTED_SIZE = 5;
			Assert::AreEqual(EXPECTED_SIZE, size);
		}

		TEST_METHOD(depthOfTree_retourne_0_quand_larbre_est_vide)
		{
			//Arrange
			Tree tree;

			//Action
			int actualDepth = tree.depthOfTree();

			//Assert
			const int EXPECTED_DEPTH = 0;
			Assert::AreEqual(EXPECTED_DEPTH, actualDepth);
		}

		TEST_METHOD(depthOfTree_retourne_1_quand_il_y_a_un_element)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number); //Teste add

			//Action
			int actualDepth = tree.depthOfTree();

			//Assert
			const int EXPECTED_DEPTH = 1;
			Assert::AreEqual(EXPECTED_DEPTH, actualDepth);
		}

		TEST_METHOD(depthOfTree_retourne_2_quand_il_y_a_deux_elements)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number); //Teste add
			IntElement any_number2(10);
			tree.add(&any_number2); //Teste add

			//Action
			int actualDepth = tree.depthOfTree();

			//Assert
			const int EXPECTED_DEPTH = 2;
			Assert::AreEqual(EXPECTED_DEPTH, actualDepth);
		}

		TEST_METHOD(depthOfTree_retourne_2_quand_il_y_a_3_elements)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number); //Teste add
			IntElement any_number2(10);
			tree.add(&any_number2); //Teste add
			IntElement any_number3(1);
			tree.add(&any_number3); //Teste add

			//Action
			int actualDepth = tree.depthOfTree();

			//Assert
			const int EXPECTED_DEPTH = 2;
			Assert::AreEqual(EXPECTED_DEPTH, actualDepth);
		}

		TEST_METHOD(depthOfTree_retourne_3_quand_il_y_a_4_elements_1_de_plus_a_gauche)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number); //Teste add
			IntElement any_number2(10);
			tree.add(&any_number2); //Teste add
			IntElement any_number3(1);
			tree.add(&any_number3); //Teste add
			IntElement any_number4(3);
			tree.add(&any_number4); //Teste add

			//Action
			int actualDepth = tree.depthOfTree();

			//Assert
			const int EXPECTED_DEPTH = 3;
			Assert::AreEqual(EXPECTED_DEPTH, actualDepth);
		}

		TEST_METHOD(depthOfTree_retourne_3_quand_il_y_a_4_elements_1_de_plus_a_droite)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number); //Teste add
			IntElement any_number2(10);
			tree.add(&any_number2); //Teste add
			IntElement any_number3(1);
			tree.add(&any_number3); //Teste add
			IntElement any_number4(15);
			tree.add(&any_number4); //Teste add

			//Action
			int actualDepth = tree.depthOfTree();

			//Assert
			const int EXPECTED_DEPTH = 3;
			Assert::AreEqual(EXPECTED_DEPTH, actualDepth);
		}

		TEST_METHOD(find_retourne_1_quand_lelement_est_le_root)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number);

			//Action
			int depthOfElement = tree.find(&any_number);

			//Assert
			const int EXPECTED_DEPTH = 1;
			Assert::AreEqual(EXPECTED_DEPTH, depthOfElement);
		}

		TEST_METHOD(find_retourne_2_quand_lelement_est_de_profondeur_deux)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			IntElement any_number2(10);
			tree.add(&any_number);
			tree.add(&any_number2);

			//Action
			int depthOfElement = tree.find(&any_number2);

			//Assert
			const int EXPECTED_DEPTH = 2;
			Assert::AreEqual(EXPECTED_DEPTH, depthOfElement);
		}

		TEST_METHOD(find_retourne_2_quand_lelement_a_une_soeur_mais_est_quand_meme_profondeur_2)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			IntElement any_number2(10);
			IntElement any_number3(3);
			tree.add(&any_number);
			tree.add(&any_number2);
			tree.add(&any_number3);

			//Action
			int depthOfElement = tree.find(&any_number3);

			//Assert
			const int EXPECTED_DEPTH = 2;
			Assert::AreEqual(EXPECTED_DEPTH, depthOfElement);
		}

		TEST_METHOD(EXCEPTION_find_catch_une_erreur_si_la_liste_est_vide)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			bool exceptionCatched = false;

			//Action
			try {
				int depth = tree.find(&any_number);
			}
			catch (...) {
				exceptionCatched = true;
			}

			//Assert
			Assert::IsTrue(exceptionCatched);
		}

		TEST_METHOD(EXCEPTION_add_catch_une_erreur_quand_un_numero_deja_ajouté_est_ajouté)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number);
			bool exceptionCatched = false;

			//Action
			try {
				tree.add(&any_number);
			}
			catch (...) {
				exceptionCatched = true;
			}

			//Assert
			Assert::IsTrue(exceptionCatched);
		}
		/*
		TEST_METHOD(find_retourne_2_quand_lelement_une_soeur_mais_est_quand_meme_profondeur_2)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			IntElement any_number2(10);
			IntElement any_number3(3);
			IntElement any_number4(3);
			tree.add(&any_number);
			tree.add(&any_number2);
			tree.add(&any_number3);
			tree.add(&any_number4);

			//Action
			int depthOfElement = tree.find(&any_number3);

			//Assert
			const int EXPECTED_DEPTH = 3;
			Assert::AreEqual(EXPECTED_DEPTH, depthOfElement);
		}

		//Tests pour find après le balance (plusieurs modèles d'arbres

		/*
		TEST_METHOD(add_catch_une_erreur_si_la_liste_est_vide)
		{
			//Arrange
			Tree tree;
			IntElement any_number(5);
			tree.add(&any_number);

			bool exceptionCatched = false;

			//Action
			try {
				tree.add(&any_number);
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