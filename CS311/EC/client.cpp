#ifndef CLIENT_C
#define CLIENT_C
// =========================================================

//EC 1 Print queue
//Your name: Christopher Wendling
//Complier:  g++
//File type: printer client file

//===========================================================
#include "printer.h"

int main()
{
	cout << "\n-----------------------------------------------------------" << endl;
	cout << "|                       Printer 1                         |" << endl;
	cout << "-----------------------------------------------------------\n" << endl;
	
	PrintQ print;		//printer queue object
	
	print.insert(2);
	print.insert(4);
	print.displayQueue();
	print.insert(5);
	print.insert(1);
	print.displayQueue();
	print.insert(6);
	print.insert(1);
	print.displayQueue();
	print.insert(8);
	print.insert(12);
	print.displayQueue();
	print.insert(3);
	print.insert(9);
	
	print.displayQueue();
	print.printJob();
	print.displayQueue();
	print.printJob();
	print.displayQueue();
	print.insert(1);
	print.insert(2);
	print.displayQueue();

	
	cout << "\n-----------------------------------------------------------" << endl;
	cout << "|                       Printer 2                         |" << endl;
	cout << "-----------------------------------------------------------\n" << endl;
	
	PrintQ print2;		//second printer queue object
	
	print2.insert(1);
	print2.insert(1);
	print2.displayQueue();
	print2.insert(1);
	print2.insert(5);
	print2.displayQueue();
	print2.insert(3);
	print2.insert(2);
	print2.displayQueue();
	print2.insert(10);
	print2.insert(11);
	print2.displayQueue();
	print2.insert(6);
	print2.insert(6);
	print2.displayQueue();
	print2.insert(9);
	print2.insert(8);
	print2.displayQueue();
	print2.insert(7);
	print2.insert(1);
	print2.displayQueue();
	print2.insert(2);
	print2.displayQueue();
	
	for(int i = 0; i < MAX; i++){	//loops until queue is cleared
		print2.printJob();
		print2.displayQueue();
	}
	print2.printJob();

	return 0;
}

#endif

