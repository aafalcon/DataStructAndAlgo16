#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
	// Location is out of range
	if (loc < 0 || loc > size_)
	{
    	throw std::invalid_argument("bad location");
  	}
  	// Create new Item to insert
	LListInt::Item* insertion= new Item;
	insertion->val= val;
	// Insert to location inside list
	if (loc > 0 && loc < size_)
	{
		LListInt::Item* insertPt= getNodeAt(loc);
		insertion->next= insertPt;
		insertion->prev= insertPt->prev;
		insertPt->prev->next= insertion;
		insertPt->prev= insertion;
	}
	// Insert a new head
	else if (loc == 0)
	{
		insertion->next= head_;
		insertion->prev= NULL;
		// Check if list is empty
		if (head_ == NULL)
		{
			tail_= insertion;
		}
		else
		{
			head_->prev= insertion;
		}
		head_= insertion;
	}
	// Insert a new tail
	else if (loc == size_)
	{
		insertion->next= NULL;
		insertion->prev= tail_;
		tail_->next= insertion;
		tail_= insertion;
	}
	++size_;
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
	// Location is out of range
	if (loc < 0 || loc >= size_)
	{
    	throw std::invalid_argument("bad location");
  	}
  	// Remove if there are items in list to remove
  	if (size_ != 0)
  	{
  		Item* temp;
	  	// Remove something that's not head or tail
	  	if (loc > 0 && loc < size_-1)
	  	{
	  		temp= getNodeAt(loc);
	  		temp->prev->next= temp->next;
	  		temp->next->prev= temp->prev;
	  		
	  	}
	  	// Remove the head
	  	else if (loc == 0)
	  	{
	  		temp= head_;
	  		// Check if there is more than 1 item in list
	  		if (temp->next != NULL)
	  		{
	  			temp->next->prev= NULL;
	  		}
	  		head_= temp->next;
	  	}
	  	// Remove the tail
	  	else if (loc == size_-1)
	  	{
	  		temp= tail_;
	  		temp->prev->next= NULL;
	  		tail_= temp->prev;
	  	}
  	delete temp;
  	--size_;
  	}

  	
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
	if(loc < 0 || loc >= size_){
    	throw std::invalid_argument("bad location");
    }
	LListInt::Item* temp= head_;
	for (int i=0; i<loc; ++i)
	{
		temp= temp->next;
	}
	return temp;
}
