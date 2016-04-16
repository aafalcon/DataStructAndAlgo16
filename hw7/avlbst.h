/*
 * avlbst.h
 *
 * Date        Author    Notes
 * =====================================================
 * 2014-04-14  Kempe     Initial version
 * 2015-04-06  Redekopp  Updated formatting and removed
 *                         KeyExistsException
 * 2016-03-31  Cote      Modify for AVL Trees
 */
#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"

template <class KeyType, class ValueType>
class AVLNode : public Node<KeyType, ValueType>
{
public:
  AVLNode (KeyType k, ValueType v, AVLNode<KeyType, ValueType> *p)
    : Node<KeyType, ValueType> (k, v, p)
    { height = 0; }
  
  virtual ~AVLNode () {}
  
  int getHeight () const
    { return height; }
  
  void setHeight (int h)
    { height = h; }
  
  virtual AVLNode<KeyType, ValueType> *getParent () const
    { return (AVLNode<KeyType,ValueType>*) this->_parent; }
  
  virtual AVLNode<KeyType, ValueType> *getLeft () const
    { return (AVLNode<KeyType,ValueType>*) this->_left; }
  
  virtual AVLNode<KeyType, ValueType> *getRight () const
    { return (AVLNode<KeyType,ValueType>*) this->_right; }
  
 protected:
  int height;
};

/* -----------------------------------------------------
 * AVL Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class AVLTree : public BinarySearchTree<KeyType, ValueType>
{
public:
  void insert (const std::pair<const KeyType, ValueType>& new_item)
  {
    AVLNode<KeyType,ValueType>* toCompare = this->root;
    AVLNode<KeyType,ValueType>* toInsert;
    AVLNode<KeyType,ValueType>* insertParent;
    toInsert  = new AVLNode<KeyType,ValueType>(new_item.first, new_item.second, NULL);
    bool rightSide;
    int new_height = 0;
    // Nothing in tree, first insertion is the root
    if (toCompare == NULL)
    {
      this->root = toInsert;
      return; // do not need to balance one node
    }
    // work down the tree until insertion location is found
    else
    {
      while (toCompare != NULL)
      {
        if (new_item.first > toCompare->getKey())
        {
          rightSide = true;
          new_height = toCompare->getHeight() + 1;
          toCompare->setHeight(new_height);
          insertParent = toCompare;
          toCompare = toCompare->getRight();
        }
        else if (new_item.first < toCompare->getKey())
        {
          rightSide = false;
          new_height = toCompare->getHeight() + 1;
          toCompare->setHeight(new_height);
          insertParent = toCompare;
          toCompare = toCompare->getLeft();
        }
        else
        {
          // throw exception
          // undo height changes
          return;
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
      // Balance Tree
      AVLNode<KeyType,ValueType>* balCheck = insertParent->getParent();
      balance(balCheck);
    }
  }
  /* This one is yours to implement.
     It should insert the (key, value) pair to the tree, 
     making sure that it remains a valid AVL Tree.
     If the key is already in the tree, you should throw an exception. */
  void remove (const KeyType &toRemove)
  {
    AVLNode<KeyType,ValueType>* toCompare = this->root;
    //there is nothing in the tree to delete
    if (toCompare == NULL)
    {
      // throw exception
    }
    // Move down tree searching for key to remove
    while (toCompare != NULL)
    {
      if (toRemove > toCompare->getKey())
      {
        toCompare = toCompare->getRight();
      }
      else if (toRemove < toCompare->getKey())
      {
        toCompare = toCompare->getLeft();
      }
      // toRemove is found, now delete
      else
      {
        AVLNode<KeyType,ValueType>* toSwap, temp, temp2;
        // Find element to replace deleted node (in-order preceding node)
        if (toCompare->getLeft() != NULL)
        {
          toSwap = toCompare->getLeft();
          // move as far right from toRemove's left child
          while (toSwap->getRight() != NULL)
          {
            toSwap = toSwap->getRight();
          }
          // toSwap's parent will inherit toSwap's left child as its right child
          bool inherit = false;
          if (toSwap->getLeft() != NULL)
          {
            temp = toSwap->getLeft;
            inherit = true;
          }
          // Replace toSwap with toCompare
          swap(toCompare, toSwap);
          temp2 = toCompare->getParent();
          delete toCompare;
          if (inherit)
          {
            temp2->setRight(temp);
          }
          // Balance up to root
          balance(temp2);
          return;
        }
        // If no left child, there could be a single right child to swap with
        else if (toCompare->getRight() != NULL)
        {
          toSwap = toCompare->getRight();
          swap(toCompare, toSwap);
          temp = toCompare->getParent();
          delete toCompare;
          // Balance 
          balance(temp);
          return;
        }
        // otherwise nothing to swap removal
        else
        {
          temp = toCompare->getParent();
          delete toCompare;
          // Balance
          balance(temp);
          return;
        }
      }
    }

  }
  /* Implement this as well.  It should remove the (key, value) pair from
   * the tree which corresponds to the input parameter.
   * If the key is not in the tree, you should throw an exception.
   */

private:
  void R_rotation(AVLNode<KeyType,ValueType> *x, AVLNode<KeyType,ValueType> *y,
    AVLNode<KeyType,ValueType> *z) 
  {
    // right rotation of z-y-x
    AVLNode<KeyType,ValueType>* temp1, temp2;
    temp1 = z->getParent();
    temp2 = y->getRight();
    y->setRight(z);
    y->setParent(temp1);
    z->setParent(y);
    z->setLeft(temp2);
    // adjust heights
    int xHt, yHt, zHt;
    xHt = x->getHeight() - 1;
    x->setHeight(xHt);
    yHt = y->getHeight() - 1;
    y->setHeight(yHt);
    zHt = z->getHeight() + 1;
    z->setHeight(zHt);
  }
  void dubR_rotation(AVLNode<KeyType,ValueType> *x, AVLNode<KeyType,ValueType> *y,
    AVLNode<KeyType,ValueType> *z) 
  {
    // Left rotation of y-x
    AVLNode<KeyType,ValueType>* temp1, temp2;
    temp1 = y->getParent();
    temp2 = x->getLeft();
    x->setLeft(y);
    x->setParent(temp1);
    y->setParent(x);
    y->setRight(temp2);
    // Right rotation of z-x-y
    AVLNode<KeyType,ValueType>* temp3, temp4;
    temp3 = z->getParent();
    temp4 = x->getRight();
    x->setRight(z);
    x->setParent(temp3);
    z->setParent(y);
    z->setLeft(temp4);
    // adjust heights
    int xHt, zHt;
    xHt = x->getHeight() - 2;
    x->setHeight(xHt);
    zHt = z->getHeight() + 1;
    z->setHeight(zHt);
  }
  void L_rotation(AVLNode<KeyType,ValueType> *x, AVLNode<KeyType,ValueType> *y,
    AVLNode<KeyType,ValueType> *z) 
  {
    // left rotation of z-y-x
    AVLNode<KeyType,ValueType>* temp1, temp2;
    temp1 = z->getParent();
    temp2 = y->getLeft();
    y->setLeft(z);
    y->setParent(temp1);
    z->setParent(y);
    z->setRight(temp2);
    // adjust heights
    int xHt, yHt, zHt;
    xHt = x->getHeight() - 1;
    x->setHeight(xHt);
    yHt = y->getHeight() - 1;
    y->setHeight(yHt);
    zHt = z->getHeight() + 1;
    z->setHeight(zHt);
  }
  void dubL_rotation(AVLNode<KeyType,ValueType> *x, AVLNode<KeyType,ValueType> *y,
    AVLNode<KeyType,ValueType> *z) 
  {
    // right rotation of y-x
    AVLNode<KeyType,ValueType>* temp1, temp2;
    temp1 = y->getParent();
    temp2 = x->getRight();
    x->setRight(y);
    x->setParent(temp1);
    y->setParent(x);
    y->setLeft(temp2);
    // left rotation of z-x-y
    AVLNode<KeyType,ValueType>* temp3, temp4;
    temp3 = z->getParent();
    temp4 = x->getLeft();
    x->setLeft(z);
    x->setParent(temp3);
    z->setParent(y);
    z->setRight(temp4);
    // adjust heights
    int xHt, zHt;
    xHt = x->getHeight() - 2;
    x->setHeight(xHt);
    zHt = z->getHeight() + 1;
    z->setHeight(zHt);
  }
  void swap(AVLNode<KeyType,ValueType>* x, AVLNode<KeyType,ValueType>* y)
  {
    AVLNode<KeyType,ValueType> *xParent, *xRight, *xLeft;
    xParent = x->getParent();
    xRight = x->getRight();
    xLeft = x->getLeft();
    
    x->setParent(y->getParent());
    x->setRight(y->getRight());
    x->setLeft(y->getLeft());
    
    y->setParent(xParent);
    y->setRight(xRight);
    y->setLeft(xLeft);
  }
  void balance(AVLNode<KeyType,ValueType>* balCheck)
  {
    AVLNode<KeyType,ValueType>* R_subtree, L_subtree, x, y, z;
    // Loop until root is reached
    while (balCheck != NULL)
    {
      R_subtree = balCheck->getRight();
      L_subtree = balCheck->getLeft();
      // When no right subtree, tree is left heavy
      if (R_subtree == NULL)
      {
        // Check if left subtree has height of at least 1
        if (L_subtree->getHeight() >= 1)
        {
          x = balCheck;
          y = L_subtree;
          // Decide whether to do a right or double-right rotation
          if (y->getRight() == NULL)
          {
            z = y->getLeft();
            R_rotation(x,y,z);
          }
          else if (y->getLeft() == NULL)
          {
            z = y->getRight();
            dubR_rotation(x,y,z);
          }
          else if (y->getLeft() > y->getRight())
          {
            z = y->getLeft();
            R_rotation(x,y,z);
          }
          else
          {
            z = y->getRight();
            dubR_rotation(x,y,z);
          }
        }
      }
      // When no left subtree, tree is right heavy
      else if (L_subtree == NULL)
      {
        // Check if right subtree has height of at least 1
        if (R_subtree->getHeight() >= 1)
        {
          x = balCheck;
          y = R_subtree;
          // Decide whether to do a left or double-left rotation
          if (y->getLeft() == NULL)
          {
            z = y->getRight();
            L_rotation(x,y,z);
          }
          else if (y->getRight() == NULL)
          {
            z = y->getLeft();
            dubL_rotation(x,y,z);
          }
          else if (y->getRight() > y->getLeft())
          {
            z = y->getRight();
            L_rotation(x,y,z);
          }
          else
          {
            z = y->getLeft();
            dubL_rotation(x,y,z);
          }
        }
      }
      // Check to see if tree is left heavy
      else if (L_subtree > R_subtree + 1)
      {
        x = balCheck;
        y = L_subtree;
        // Decide whether to do a right or double-right rotation
        if (y->getRight() == NULL)
        {
          z = y->getLeft();
          R_rotation(x,y,z);
        }
        else if (y->getLeft() == NULL)
        {
          z = y->getRight();
          dubR_rotation(x,y,z);
        }
        else if (y->getLeft() > y->getRight())
        {
          z = y->getLeft();
          R_rotation(x,y,z);
        }
        else
        {
          z = y->getRight();
          dubR_rotation(x,y,z);
        }
      }
      // Check to see if tree is right heavy
      else if (R_subtree > L_subtree + 1)
      {
        x = balCheck;
        y = R_subtree;
        // Decide whether to do a left or double-left rotation
        if (y->getLeft() == NULL)
        {
          z = y->getRight();
          L_rotation(x,y,z);
        }
        else if (y->getRight() == NULL)
        {
          z = y->getLeft();
          dubL_rotation(x,y,z);
        }
        else if (y->getRight() > y->getLeft())
        {
          z = y->getRight();
          L_rotation(x,y,z);
        }
        else
        {
          z = y->getLeft();
          dubL_rotation(x,y,z);
        }
      }
      balCheck = balCheck->getParent();
    }
  }
};

#endif
