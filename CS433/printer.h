#ifndef PRINT_H
#define PRINT_H
// =========================================================

//EC 1 Print queue
//Your name: Christopher Wendling
//Complier:  g++
//File type: printer header file

//===========================================================
#include <iostream>
#include <string>
using namespace std;

typedef int el_t;	//type define for elements
const int MAX = 25;		//queue size

struct PCBtable
{
	int ID;
	string state;
	el_t priority;
};

struct ReadyQueue
{
	el_t p_lvl;
	int id;
};

class PrintQ
{
	private:
		ReadyQueue queue[MAX];	//heap ready queue
		PCBtable table;		//Process control block table
		int count;		//counter for jobs in queue
		
		//Purpose: To take the bottom, right most element and move to top then sort downward.
		//How To Call: Only reheapify() will call this.
		void trickleDown();
		
		//Purpose: To take a recently added element and sort upward.
		//How To Call: Only reheapify() will call this.
		void trickleUp(int);
		
		//Purpose: To sort a heap tree.
		//How To Call: Function will be called when adding or removing an element from queue.
		void reheapify(int);
		
		//Purpose: To return the parent for your current index.
		//How To Call: Pass a valid index in your heap tree.
		int getParent(int);
		
		//Purpose: To return the index of the bottom, right most element.
		//How To Call: client cannot access this.
		int getLast();
		
	public:	
		PrintQ();	//CTOR
		~PrintQ() {};	//DTOR
	
		//Purpose: To insert an element into the queue given by client.
		//How To Call: Pass a queue element from client.
		void insert(el_t);
		
		//Purpose: To remove the first job in the queue and show it on the screen.
		//How To Call: client calls to pop off first element.
		void printJob();
		
		//Purpose: To display the remaining jobs in the queue
		//How To Call: Client can call at any time.
		void displayQueue();		
};

#endif

