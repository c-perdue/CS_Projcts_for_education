// =========================================================

//HW1P2 queue client
//Your name: Christopher Wendling
//Complier:  g++
//File type: client run file

//================================================================

#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int main()
{
	queue alphaqueue;
	string base = {"ABC"};		//initialize a string to add together later
	string item;
	
	while(!alphaqueue.isFull()){
		try{
			for(int i = 0; i < base.size(); ++i)
				alphaqueue.add(item + base[i]);		//appends two strings then adds back on queue
			
			alphaqueue.displayAll();
			alphaqueue.remove(item);		//removes string front front of queue
			
		}
		catch(queue::Overflow){
			cout << "Queue is full....come back later." << endl;
			exit(1);
		}
		catch(queue::Underflow){
			cerr << "***Stack Underflow*** : Ending Program." << endl;
			exit(1);
		}
	}
	return 0;
}