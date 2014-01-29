#ifndef CLIENT2_C
#define CLIENT2_C

// =========================================================

//HW7 part 2
//Your name: Christopher Wendling
//Complier:  g++
//File type: DFS Client file

//===========================================================
#include "graph.h"
#include "stack.h"

int main()
{
	slist temp;		//holder for slist objects upon return
	stack list;		//stack object
	Dgraph graph;	//Dgraph object initialization 
	el_t x = 'a';			//temp holder for user input
	int count = 1;		//counter for order assignment
	int deg;		//temp degree holder
	
	graph.fillTable();		//read in from text file
	graph.displayGraph();	

	graph.visit(1,x);		//assign visit to first element
	
	temp = graph.findAdjacent(x);	//returns adjacency list for first element
	deg = graph.findDegree(x);	//gets the out degree for first adjacency list
	cout << "\nPopped '" << char(toupper(x)) << "' from Stack." << endl;
	cout << "Adding.... ";
	temp.displayAll();
	for(int i =0; i < deg; ++i){	//while i < out degree
		temp.deleteRear(x);		//return element by reference 
		list.push(x);	//push onto the stack
	}
	cout << "\nCurrent stack:\n--------------" << endl;
	list.displayAll();
	
	while(!list.isEmpty()){		//loop until stack is empty
		deg = 0; 	//reset degree holder
		count++;	//increment counter for visit order
		list.pop(x);	//gets top element of stack
		cout << "\nPopped '" << x << "' from Stack." << endl;
		if(!graph.isMarked(x)){		//while element has not been visited yet
			graph.visit(count,x);	//update visit number
			temp = graph.findAdjacent(x);	//get adjacency list
			deg = graph.findDegree(x);		//gets out degree for element
			cout << "Adding.... ";
			temp.displayAll();
			for(int i =0; i < deg; ++i){	//adds adjacency list to stack
				temp.deleteRear(x);
				list.push(x);
			}
		}
		else
			cout << "'" << x << "' is already marked";
			
		cout << "\nCurrent stack:\n--------------" << endl;
		list.displayAll();
	}
	graph.displayGraph();
	return 0;
}
#endif

