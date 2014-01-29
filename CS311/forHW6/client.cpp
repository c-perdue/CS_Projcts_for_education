#ifndef CLIENT_C
#define CLIENT_C

// =========================================================

//HW6
//Your name: Christopher Wendling
//Complier:  g++
//File type: Dgraph Client file

//===========================================================
#include "graph.h"

int main()
{
	slist temp;		//holder for slist objects upon return
	Dgraph graph;	//Dgraph object initialization 
	el_t x;			//temp holder for user input
	
	graph.fillTable();		//read in from text file
	graph.displayGraph();	
	
	do{				//loop while user has more requests, until kill value entered
		cout << "\nEnter vertex letter to find out degree or '9' to quit: ";
		cin >> x;
		if(x == '9')	//if kill value was entered break loop
			break;
		else
			cout << "The degree at '" << char(toupper(x)) << "' is: " << graph.findDegree(x) << endl;
	}while(x != '9');	//redundant kill value check
	
	do{				//loop while user has more requests, until kill value entered
		cout << "\nEnter vertex letter to find adjacency list or '9' to quit: ";
		cin >> x;
		if(x == '9')	//if kill value was entered break loop
			break;
		else{
			cout << "The adjacency list at '" << char(toupper(x)) << "' is." << endl;
			temp = graph.findAdjacent(x);	//returns slist into temp
			temp.displayAll();		//temp calls slist function displayAll()
		}
	}while(x != '9');	//redundant kill value check

	return 0;
}

#endif

