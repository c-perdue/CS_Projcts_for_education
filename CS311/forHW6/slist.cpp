#ifndef SLIST_C
#define SLIST_C
/*
// ====================================================

HW3P3 searchable link list
Your name: Christopher Wendling
Complier:  g++
File type: implementation file

//=====================================================
*/
#include "slist.h"

//---------------------------------------------------------------
//Purpose: To deep copy an old list upon creation of a new list
//Param: Takes an slist object from user
//Modified: 102013
slist::slist(const slist& source)
{
  nodeptr p = source.front;		//Node pointer set to front of source list
  while(p != NULL){		//loop until pointer reaches end of source list
    this->addRear(p->elem);		//calls new objects function to add old elements
    p = p->next;		//increments pointer in source list
  }
}
//---------------------------------------------------------------
//Purpose: To preform a deep copy from one list to another using = sign
//Param: Pass by reference slist object
//Return: referenced slist object that received copied information
//Modified: 102113
slist& slist::operator= (const slist& tempList)
{
	el_t oldNum;		//holds old element after deletion 
	if(&tempList != this){		//if not pointing to same list then clear this->list
		while(! this->isEmpty())	//loop until this->list is clear
			this->deleteRear(oldNum);
		
		nodeptr p = tempList.front;		//Node pointer set to front of old list
		while(p != NULL){		//loop until pointer reaches end of old list
			this->addRear(p->elem);		//adds to read of this->list
			p = p->next;	//increments pointer to next Node
		}
	}
	return *this;	//returns pointer to this->object
}
//---------------------------------------------------------------
//Purpose: to compare two slist objects for equality
//Param: pass by reference an slist object
//Return: bool true if equal, false if not
//Modified: 102113
bool slist::operator== (slist& tempList)
{
	if((this->isEmpty()) && (tempList.isEmpty())){	//when both lists are empty show warning
		cout << "***Warning***: Both lists are empty." << endl;
		return true;	//since they are still equal return true
	}
	//when only one list is empty we know they are not equal
	else if(((this->isEmpty()) && (!tempList.isEmpty())) || ((!this->isEmpty()) && (tempList.isEmpty())))
		return false;
	else{		//otherwise test each element for equality
		nodeptr p = this->front;	//Node pointer set to front of this->list
		nodeptr q = tempList.front;	//Node pointer set to front of second list
		
		while((p != NULL) || (q != NULL)){ //loops until we reach the end of one list
			if(p->elem == q->elem){ //when both elements are the same, increment both pointers
				p = p->next;
				q = q->next;
			}
			else 	//otherwise lists are not equal return false
				return false;
				
			if(p == NULL && q == NULL)	//when both lists have reached their ends they must be equal
				return true;
			else if(p == NULL || q == NULL) //or one list has reached its end we return false
				return false;
		}		
	}
	return false;	//redundant return statement in case or errors
}
//---------------------------------------------------------------
//Purpose: To search a list for a given element
//param: type el_t given from user
//return: int index where found element is found or zero if not found 
//Modified: 101413
int slist::search(el_t key)
{
	if(isEmpty())	//checks if empty
		return 0;

	nodeptr p = front;	//Node pointer set to front of list
	int j = 1;		//counter for position we find element in
	
	while(p != NULL){		//loops until end of list
		if(p->elem == key)	//when Node element has been found
			return j;		//return current position
		
		p = p->next;	//else move to next Node
		++j;		//increment counter
	}
	return 0;	//if not found 
}
//---------------------------------------------------------------
//Purpose: To replace the element at a given location 
//Param: type el_t element, and an int index
//Modified: 101413 
void slist::replace(el_t key, int i)
{
	if(isEmpty())	//when empty throw error
		throw UnderFlow();
	else if((i < 1) || (i > count))	//when index is out of range of list throw error
		throw OutOfRange();
	else if(i == count)	//when index given is end of list, replace element
		rear->elem = key;
	else{		//otherwise replace the element
		nodeptr p = front;		//Node pointer set to front of list
		for(int j = 1; j <= i; ++j){	//loops until it reaches given index i
			if(j == i)		//when we reach given index i replace element
				p->elem = key;
			p = p->next;		//otherwise move to next Node
		}
	}
}
#endif

