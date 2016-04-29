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
		if (curr != NULL)
		{
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
		      while (toCompare != NULL)
		      {
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
		      }
		      // Insert to right of dead end
		      if (rightSide)
		      {
		        insertParent->setRight(toInsert);
		        toInsert->setParent(insertParent);
		      }
		      // Insert to left of dead end
		      else
		      {
		        insertParent->setLeft(toInsert);
		        toInsert->setParent(insertParent);
		      }
			}

			// splay inserted node
			splay(toInsert);
		}
	}
	void reportAll(std::ostream& output)
	{
		/*
		for (BinarySearchTree<std::string,int>::iterator it = this->begin();
			it != this->end(); ++it)
		{
			output << (*it).first << " " << (*it).second << std::endl;
		}
		*/
		this->printRoot(this->root, output);
		output << std::endl;
	}
	
	/*
	void check(std::ostream& output, int checkNum)
	{
		if (checkNum == 1)
		{
			if (this->root->getKey() == "Bravo" && this->root->getLeft()->getKey() == "Alpha" 
				&& this->root->getRight()->getKey() == "Charlie")
			{
				output << "SUCCESS" << std::endl;
			}
			else
			{
				output << "FAILURE" << std::endl;
			}
		}
		else if (checkNum == 2)
		{
			if (this->root->getKey() == "Alpha" && this->root->getRight()->getKey() == "Bravo" 
				&& this->root->getRight()->getRight()->getKey() == "Charlie")
			{
				output << "SUCCESS" << std::endl;
			}
			else
			{
				output << "FAILURE" << std::endl;
			}
		}
		
	}
	*/

private:
	void splay(Node<KeyType,ValueType>* x)
	{
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
						RR_rotation(x,p,g);
					}
					else
					{
						// RIGHT
						LR_rotation(x,p,g);
					}
				}
				else
				{
					// RIGHT
					if (x->getKey() < p->getKey())
					{
						// LEFT
						RL_rotation(x,p,g);
					}
					else
					{
						// RIGHT
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
					R_rotation(x,p);
				}
				else
				{
					// RIGHT
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
	}
};

#endif