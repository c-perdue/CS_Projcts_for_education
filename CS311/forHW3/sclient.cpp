#ifndef SCLIENT_C
#define SCLIENT_C
/*
// ====================================================

HW3P2 searchable link list
Your name: Christopher Wendling
Complier:  g++
File type: client file

//=====================================================
*/
#include "slist.h"

int main()
{
	slist List;		//creates an object of slist
	int pos;	//will hold the index returned from search()
	
	try{
		cout << "\n------------------------------------------------" << endl;
		cout << "                     Case 1                     " << endl;
		cout << "------------------------------------------------" << endl;
		List.addFront(4);
		List.addRear(6);
		List.addRear(7);
		List.addRear(8);
		List.displayAll();
		pos = List.search(6);
		cout << "Number was located in position: " << pos << endl;
		List.replace(0, pos);
		pos = List.search(8);
		cout << "Number was located in position: " << pos << endl;
		List.replace(2, pos);
		List.displayAll();
		pos = List.search(5);
		if(pos == 0)	//when element not found throw error
			throw "Item not located.";
		else		//otherwise print position
			cout << "Number was located in position: " << pos << endl;
	}
	catch(llist::UnderFlow){
		cerr << "***Error***: No items in list." << endl;
	}
	catch(llist::OutOfRange){
		cerr << "***Error***: Item requested not in range of list." << endl;
	}
	catch(char const* error){		
		cerr << "***Error***: " << error << endl;
	}
	return 0;
}
#endif

