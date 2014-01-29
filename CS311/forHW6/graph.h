#ifndef GRAPH_H
#define GRAPH_H

// =========================================================

//HW7 part 2
//Your name: Christopher Wendling
//Complier:  g++
//File type: Dgraph Header file

//===========================================================
#include <iostream>
#include <string>
#include "slist.h"
using namespace std;

const int SIZE = 20;

struct Gvertex		//to be used in each Gtable slot.
{
	el_t name;        //the vertex Name
	int degree;		  //the Out degree
	slist adjacent;   //the adjacent vertices in an slist
	int visited;	  //holds the visit number
};
//------------------------------------------------------------
class Dgraph
{

private:
	Gvertex Gtable[SIZE];	//Gtable matrix
	int  slots; 		// how many slots of the Gtable are actually used

public:
	Dgraph();  		//CTOR
	~Dgraph(){};	//DTOR

	//Purpose: To read in a G table from a text file.
	//How To Call: Call with Dgraph object, no parameters needed.
	void fillTable(); 

	//Purpose: To display the entire graph in an easy to read format
	//How To Call: Call with Dgraph object, no parameters needed.
	void displayGraph(); 
	
	//Purpose: To return the out degree for a given list head.
	//How To Call: Pass user defined list head from client.
	int findDegree(el_t); 
		
	//Purpose: To return the linked list at the given list head.
	//How To Call: Pass user defined list head from client
	slist findAdjacent(el_t);  
	
	//Purpose: Assigns a visited order number to Gtable element.
	//How To Call: Pass an order number, and a Gtable element to assign order to.
	void visit(int, el_t);
	
	//Purpose: To determine if an element has been visited or not.
	//How To Call: pass a Gtable element to check.
	bool isMarked(el_t);
};

#endif

