#ifndef GRAPH_C
#define GRAPH_C

// =========================================================

//HW7 part 2
//Your name: Christopher Wendling
//Complier:  g++
//File type: Dgraph Implementation file

//===========================================================
#include <fstream>
#include "graph.h"

//--------------------------------------------------------------
//Constructor
Dgraph::Dgraph()
{
	for(int i = 0; i < SIZE; ++i){		//initializes all elements of our table
		Gtable[i].visited = 0;
		Gtable[i].name = ' ';
	}
	slots = 0;		//sets counter for table
}
//--------------------------------------------------------------
//Purpose: To read in a table from a text file and put values into our table.
//Modified: 111713
void Dgraph::fillTable()
{
	int i = 0;		//incrementing variable for our table
	el_t x;			//temp holder for adjacent nodes
	ifstream fin;	//fstream object
	fin.open("table.txt");		//opens text file
	
	while(fin >> Gtable[i].name){	//loop until no more items can be read
		slots++;		//increment table count
		fin >> Gtable[i].degree;	//reads in out degree
		for(int j = 0; j < Gtable[i].degree; ++j){	//while j < out degree
			fin >> x;		//read in adjacent node
			(Gtable[i].adjacent).addRear(x);	//append node to end of linked list
		}
		++i;	//increments table position
	}
	fin.close();	//close file
}
//--------------------------------------------------------------
//Purpose: To display the entire graph in a well formatted manner.
//Modified: 111813
void Dgraph::displayGraph()
{
	for(int i = 0; i < slots; ++i){		//while i is < #of slots used
		cout << endl;
		cout << Gtable[i].name << " ";
		cout << Gtable[i].degree << " --->";
		if(Gtable[i].degree > 0)		//when is greater than zero
			(Gtable[i].adjacent).displayAll();	//calls slist function displayAll()

		cout << " Visit# " << Gtable[i].visited << endl;
	}
}
//--------------------------------------------------------------
//Purpose: To find a user defined list head and return its out degree.
//Param: type el_t given from user.
//Return: An int out degree at the given list head.
//Modified: 111813
int Dgraph::findDegree(el_t x)
{
	x = toupper(x);		//convert clients input to upper case
	for(int i = 0; i < slots; ++i)	//while i < #of slots used
		if(x == Gtable[i].name)		//if requested list head is found
			return Gtable[i].degree;	//return out degree
	cout << "Your vertex was not found!" << endl;	//when list head not found
	return -1;
}
//--------------------------------------------------------------
//Purpose: To find a user defined list head and return its adjacency list.
//Param: type el_t given from user.
//Return: An slist object.
//Modified: 111813
slist Dgraph::findAdjacent(el_t x)
{
	x = toupper(x);		//convert clients input to upper case
	for(int i = 0; i < slots; ++i)	//while i < #of slots used
		if(x == Gtable[i].name)		//when requested list head is found
			return Gtable[i].adjacent;	//return adjacency list object
	cout << "Your vertex was not found!" << endl;
	slist temp;		//creates Null slist object to be returned
	return temp;		
}
//--------------------------------------------------------------
//Purpose: Assigns a visited order number to Gtable element.
//Param: int number for order visited, and the element from top of stack.
//Modified: 112513
void Dgraph::visit(int order, el_t x)
{
	x = toupper(x);		//converts element to upper case
	for(int i = 0; i < slots; ++i)	//while i < #of slots used
		if(Gtable[i].name == x)		//when element passed equals current element
			Gtable[i].visited = order;	//assigns order number to current element
}
//--------------------------------------------------------------
//Purpose: To determine if an element has been visited or not.
//Param: An element to be checked for if its marked or not.
//Return: true if element is marked and false if not.
//Modified: 112513
bool Dgraph::isMarked(el_t x)
{
	for(int i = 0; i < slots; ++i)	//while i < #of slots used
		if(Gtable[i].name == x)		//when element is found
			if(Gtable[i].visited != 0)	//and visit# not equal to 0
				return true;
	
	return false;	//when already marked
}
#endif


