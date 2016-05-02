#ifndef SPLTREE_H
#define SPLTREE_H

#include "bst.h"
#include "Map.h"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>

template <class KeyType, class ValueType>
class SplayTree : public Map, public BinarySearchTree<KeyType, ValueType>
{
public:
	void add(const std::string& word)
	{
		// change uppercase characters to lowercase
		std::string word1 = word; // copy word to edit
		for (int i=0; i < word1.length(); ++i)
		{
			// get ASCII value of character
			int letter = (int)word1[i];
			int newLetter;
			if (letter >= 65 && letter <= 90)
			{
				newLetter = letter + 32;
				word1[i] = (char)newLetter;
			}
		}

		Node<KeyType, ValueType>* curr = this->internalFind(word1);
		//std::cerr << "TO ADD: " << word1 << std::endl << std::endl;
		if (curr != NULL)
		{
			//std::cerr << "---FOUND!---" << std::endl;
			curr->setValue(curr->getValue() + 1);
			splay(curr);
		}
		else
		{
			Node<KeyType,ValueType>* toCompare = this->root;
		    Node<KeyType,ValueType>* toInsert = new Node<KeyType,ValueType>(word1, 1, NULL);
		    Node<KeyType,ValueType>* insertParent = NULL;
		    bool rightSide;
		    // Nothing in tree, first insertion is the root
		    if (toCompare == NULL)
		    {
		      this->root = toInsert;
		      return; 
		    }
		    // work down the tree until insertion location is found
		    else
		    {
		      int i=0; //DEBUG
		      while (toCompare != NULL)
		      {
		      	//std::cerr << "COMPARISON# " << i << std::endl; //DEBUG
		        if (word1 > toCompare->getKey())
		        {
		          rightSide = true;
		          insertParent = toCompare;
		          toCompare = toCompare->getRight();
		        }
		        else
		        {
		          rightSide = false;
		          insertParent = toCompare;
		          toCompare = toCompare->getLeft();
		        }
		        ++i; //DEBUG
		      }
		      // Insert to right of dead end
		      if (rightSide)
		      {
		        insertParent->setRight(toInsert);
		        toInsert->setParent(insertParent);
		        //std::cerr << "***PLACED(RIGHT)" << std::endl; //DEBUG
		      }
		      // Insert to left of dead end
		      else
		      {
		        insertParent->setLeft(toInsert);
		        toInsert->setParent(insertParent);
		        //std::cerr << "***PLACED(LEFT)" << std::endl; //DEBUG
		      }
			}

			// splay inserted node
			splay(toInsert);
		}
		/*
		std::cerr << "Added: " << word1 << std::endl; //DEBUG
		reportAll(std::cerr); //DEBUG
		std::cerr << std::endl; //DEBUG
		*/
	}
	void reportAll(std::ostream& output)
	{
		//std::cerr << "---Report---" << std::endl; //DEBUG
		this->printRoot(this->root, output);
		output << std::endl;
	}

private:
	void splay(Node<KeyType,ValueType>* x)
	{
		//std::cerr << "---SPLAY!---" << std::endl;
		if (x->getParent() == NULL)
		{
			this->root = x;
			return;
		}
		else
		{
			Node<KeyType,ValueType>* p = x->getParent();
			if (p->getParent() != NULL)
			{
				// 3 Nodes
				Node<KeyType,ValueType>* g = p->getParent();
				if (p->getKey() < g->getKey())
				{
					// LEFT
					if (x->getKey() < p->getKey())
					{
						// LEFT
						//std::cerr << "__RR__" << std::endl;
						RR_rotation(x,p,g);
					}
					else
					{
						// RIGHT
						//std::cerr << "__LR__" << std::endl;
						LR_rotation(x,p,g);
					}
				}
				else
				{
					// RIGHT
					if (x->getKey() < p->getKey())
					{
						// LEFT
						//std::cerr << "__RL__" << std::endl;
						RL_rotation(x,p,g);
					}
					else
					{
						// RIGHT
						//std::cerr << "__LL__" << std::endl;
						LL_rotation(x,p,g);
					}
				}
			}
			else
			{
				// 2 Nodes
				if (x->getKey() < p->getKey())
				{
					// LEFT
					//std::cerr << "__R__" << std::endl;
					R_rotation(x,p);
				}
				else
				{
					// RIGHT
					//std::cerr << "__L__" << std::endl;
					L_rotation(x,p);
				}
			}
			splay(x);
		}
		
	}

	void R_rotation(Node<KeyType,ValueType> *x, Node<KeyType,ValueType> *y)
	{
		// alter x
		Node<KeyType,ValueType>* temp1 = x->getRight();
		x->setRight(y);
		x->setParent(NULL);
		// alter y
		y->setLeft(temp1);
		y->setParent(x);
		// alter temps
		if (temp1 != NULL)
		{
			temp1->setParent(y);
		}
	}

	void L_rotation(Node<KeyType,ValueType> *x, Node<KeyType,ValueType> *y)
	{
		// alter x
		Node<KeyType,ValueType>* temp1 = x->getLeft();
		x->setLeft(y);
		x->setParent(NULL);
		// alter y
		y->setRight(temp1);
		y->setParent(x);
		// alter temps
		if (temp1 != NULL)
		{
			temp1->setParent(y);
		}
	}

	void RR_rotation(Node<KeyType,ValueType> *x, Node<KeyType,ValueType> *y,
    	Node<KeyType,ValueType> *z) 
	{
		// alter x
		Node<KeyType,ValueType>* temp1 = x->getRight();
		x->setRight(y);
		x->setParent(z->getParent());
		// alter y
		Node<KeyType,ValueType>* temp2 = y->getRight();
		y->setRight(z);
		y->setLeft(temp1);
		y->setParent(x);
		// alter z
		z->setLeft(temp2);
		z->setParent(y);
		// alter temps
		if (temp1 != NULL)
		{
			temp1->setParent(y);
		}
		if (temp2 != NULL)
		{
			temp2->setParent(z);
		}
	}

	void LL_rotation(Node<KeyType,ValueType> *x, Node<KeyType,ValueType> *y,
    	Node<KeyType,ValueType> *z) 
	{
		// alter x
		Node<KeyType,ValueType>* temp1 = x->getLeft();
		x->setLeft(y);
		x->setParent(z->getParent());
		// alter y
		Node<KeyType,ValueType>* temp2 = y->getLeft();
		y->setLeft(z);
		y->setRight(temp1);
		y->setParent(x);
		// alter z
		z->setRight(temp2);
		z->setParent(y);
		// alter temps
		if (temp1 != NULL)
		{
			temp1->setParent(y);
		}
		if (temp2 != NULL)
		{
			temp2->setParent(z);
		}
	}

	void LR_rotation(Node<KeyType,ValueType> *x, Node<KeyType,ValueType> *y,
    	Node<KeyType,ValueType> *z) 
	{
		// alter x
		Node<KeyType,ValueType>* temp1 = x->getLeft();
		Node<KeyType,ValueType>* temp2 = x->getRight();
		x->setLeft(y);
		x->setRight(z);
		x->setParent(z->getParent());
		// alter y
		y->setRight(temp1);
		y->setParent(x);
		// alter z
		z->setLeft(temp2);
		z->setParent(x);
		// alter temps
		if (temp1 != NULL)
		{
			temp1->setParent(y);
		}
		if (temp2 != NULL)
		{
			temp2->setParent(z);
		}
	}

	void RL_rotation(Node<KeyType,ValueType> *x, Node<KeyType,ValueType> *y,
    	Node<KeyType,ValueType> *z) 
	{
		// alter x
		Node<KeyType,ValueType>* temp1 = x->getLeft();
		Node<KeyType,ValueType>* temp2 = x->getRight();
		x->setLeft(z);
		x->setRight(y);
		x->setParent(z->getParent());
		// alter y
		y->setLeft(temp2);
		y->setParent(x);
		// alter z
		z->setRight(temp1);
		z->setParent(x);
		// alter temps
		if (temp1 != NULL)
		{
			temp1->setParent(z);
		}
		if (temp2 != NULL)
		{
			temp2->setParent(y);

		}
	}
};

#endif