#ifndef PRINT_C
#define PRINT_C
// =========================================================

//EC 1 Print queue
//Your name: Christopher Wendling
//Complier:  g++
//File type: printer implementation file

//===========================================================
#include <cmath>
#include "printer.h"

//CTOR
//--------------------------------------------------
PrintQ::PrintQ()
{
	count = 0;
	for(int i = 0; i < MAX; ++i)	//initialize all values in queue
		queue[i] = 0;
}
//--------------------------------------------------
//Purpose: To add an element to the queue.
//Param: type el_t given from user.
//Modified: 120113
void PrintQ::insert(el_t x)
{
	if(x <= 0){		//when priority passed is invalid
		cout << "***ERROR***: '" << x << "' is an invalid priority." << endl;
		return;
	}
	
	if(count == 0){		//when queue empty insert at front
		queue[0] = x;
		count++;
		cout << "Job inserted."<< endl;
	}
	else if(count == MAX){
		cout << "***ERROR***: Unable to add job, queue is full." << endl;
	}
	else{		//otherwise find next open slot
		for(int i = 0; i < MAX;){	//loops until end of queue
			if(queue[i] > 0)	//when slot has an element increment i
				i++;
			else{		//otherwise store element in this index
				queue[i] = x;
				count++;
				cout << "Job inserted." << endl;
				reheapify(i);		//resorts the tree
				break;
			}
		}
	}
}
//--------------------------------------------------
//Purpose: To sort a heap tree
//Param: int index of where to begin your sort
//Modified: 120113
void PrintQ::reheapify(int index)
{
	if(count <= 0)	//when nothing in queue to sort
		return;
	else if(index == 0)		//sort from top down
		trickleDown();
	else			//sorts from specific index up to top
		trickleUp(index);
		
	cout << "Reheapified! " << endl;
}
//--------------------------------------------------
//Purpose: To take the bottom, right most element and sort it down from top.
//Modified: 120213
void PrintQ::trickleDown()
{
	if(count <= 0)		//when queue is empty
		return;
		
	el_t temp;		//holds elements
	int left, right;	//holds indexes 
	int j = getLast();	//hold the bottom, right most index
	temp = queue[j];
	queue[j] = 0;
	queue[0] = temp;
	
	for(int i = 0; i < MAX;){	//loop until end of queue
		left = i+(i+1);		//sets left child
		right = i+(i+2);	//sets right child
		if((queue[left] == 0) && (queue[right] == 0))	//when parent is a leaf
			return;
		else if((queue[left] == 0) && (queue[right] != 0)){	//when parent only has right child
			if(queue[right] < queue[i]){	//and that child is less than the parent
				temp = queue[right];
				queue[right] = queue[i];
				queue[i] = temp;
				i = right;		//moves parent index to child
			}
			else
				return;
		}
		else if((queue[right] == 0) && (queue[left] != 0)){	//when parent only has a left child
			if(queue[left] < queue[i]){		//and that child is less than the parent
				temp = queue[left];
				queue[left] = queue[i];
				queue[i] = temp;
				i = left;		//moves parent index to child
			}
			else
				return;
		}
		else if(queue[right] <= queue[left]){	//when right child is smaller
			if(queue[right] < queue[i]){		//and is smaller than parent
				temp = queue[right];
				queue[right] = queue[i];
				queue[i] = temp;
				i = right;		//moves parent to index of child
			}
			else
				return;
		}
		else if(queue[left] <= queue[right]){ //when left child is smaller
			if(queue[left] < queue[i]){		//and is smaller than parent
				temp = queue[left];
				queue[left] = queue[i];
				queue[i] = temp;
				i = left;		//moves parent to index of child
			}
			else
				return;
		}
	}
}
//--------------------------------------------------
//Purpose: To sort the heap from a specific index from bottom to top.
//Param: int index of where to start.
//Modified: 120113
void PrintQ::trickleUp(int index)
{
	el_t temp;		//holds elements
	for(int i = index; i >= 0; index=i){	//loop until we reach the root
		i = getParent(index);		//gets the parent index for a child
		if(queue[i] <= queue[index])	//when parent is smaller than child
			return;
		else{		//otherwise switch child with parent and continue
			temp = queue[i];
			queue[i] = queue[index];
			queue[index] = temp;
		}
	}
}
//--------------------------------------------------
//Purpose: To return the index of a parent.
//Param: int index of the child
//Return: int index of child's parent
//Modified: 113013
int PrintQ::getParent(int i)
{
	if((i % 2) > 0)		//when child is an odd index
		i = int(floor(i / 2));
	else if((i % 2) == 0)	//when child is an even index
		i = (i / 2) - 1;
		
	return i;		//returns parent index
}
//--------------------------------------------------
//Purpose: To get the bottom, right most element's index
//Return: int index for bottom element
//Modified: 113013
int PrintQ::getLast()
{
	int i = MAX - 1;	//starts at rear of queue
	while(queue[i] == 0)	//loops while slots are empty
		i--;
		
	if(i <= 0)		//if no element was found, queue is empty
		return 0;
		
	return i;
}
//--------------------------------------------------
//Purpose: To remove first job in queue and print it to the screen.
//Modified: 120213
void PrintQ::printJob()
{
	if(count == 0){		//when queue is empty
		cout << "Queue is empty." << endl;
		return;
	}
	else{		//otherwise print first job
		cout << "Job printed!" << "\tPriority level: " << queue[0] << endl;	
		queue[0] = 0;	//clears first job from queue
		cout << "Jobs left: " << --count << endl;
		reheapify(0);	//resorts the heap
	}
}
//--------------------------------------------------
//Purpose: To display all remaining jobs in queue
//Modified: 113013
void PrintQ::displayQueue()
{
	if(count == 0){		//when queue is empty
		cout << "Nothing to display." << endl;
		return;
	}
    cout << "\n[";
    for(int i = 0; i < count; ++i){		//displays only up to number of jobs not entire queue
		cout << queue[i];
		if(i != count - 1)	//when not at last element
			cout << ", ";
	}
	cout << "]" << endl;
}

#endif

