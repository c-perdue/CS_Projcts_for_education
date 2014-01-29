#ifndef SLIST_H
#define SLIST_H
/*
// ====================================================

HW3P3 searchable link list
Your name: Christopher Wendling
Complier:  g++
File type: header file

//=====================================================
*/
#include <iostream>
using namespace std;

#include "llist.h"

class slist: public llist	//gives slist access to all public and protected items 
{
	public:
		//called llist's ctor since we didn't need to do anything different
		slist():llist() {};	
		
		//copy ctor
		//How to call: pass an slist object when creating new slist object
		//Purpose: to preform a deep copy of all elements in a list
		slist(const slist& source);
		
		//How to call: User passes an element to find in a list
		//Purpose: To find the given element in our list
		int search(el_t key);
		
		//How to call: User passes an element to be added and the position of the element to replace
		//Purpose: To replace the element at a given location with a new element
		void replace(el_t key, int i);
		
		//How to call: use the = sign with two slist objects
		//Purpose: to preform a deep copy on a list
		slist& operator= (const slist& tempList);
		
		//How to call: use == sign with two slist objects
		//Purpose: to compare two slist objects and return if equal or not
		bool operator== (slist& tempList);
};
#endif

