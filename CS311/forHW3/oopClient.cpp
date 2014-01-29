#ifndef OOPCLIENT_C
#define OOPCLIENT_C
/*
// ====================================================

HW3P3	Operator overloading 
Your name: Christopher Wendling
Complier:  g++
File type: client file

//=====================================================
*/
#include "slist.h"

void copyTest(slist tempList);		//client function prototypes

int main()
{
	slist L1;		//declares new slist object
	int oldNum;		//holds old element after deletion
	
	L1.addRear(1);
	L1.addRear(2);
	L1.addRear(3);
	L1.addRear(4);
	L1.addRear(5);
	copyTest(L1);
	L1.displayAll();
	L1 = L1;
	L1.displayAll();
	
	slist L2;		//declares another slist object
	
	L2.addRear(7);
	L2.addRear(8);
	L2.addRear(9);
	L2.addRear(10);
	L2.displayAll();
	L2 = L1;
	L2.displayAll();
	L1.deleteRear(oldNum);
	L1.displayAll();
	L2.displayAll();
	
	return 0;
}
//----------------------------------------------------------------
//Purpose: to test what happens when our object gets passed by value
//Param: slist object passed by value
//Modified: 102113
void copyTest(slist tempList)
{
	tempList.addRear(6);	//adds new element to list
	tempList.displayAll();
}
#endif

