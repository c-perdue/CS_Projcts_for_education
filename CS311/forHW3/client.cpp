/*
// ====================================================

HW3P1 link list
Your name: Christopher Wendling
Complier:  g++
File type: client file

//=====================================================
*/
#include "llist.h"

int main()
{
	llist L;		//declares a new llist object.
	
	cout << "\n\n----------------------------------------------------" << endl;
	cout << "                        CASE 1                      " << endl;
	cout << "----------------------------------------------------" << endl;
	L.case1();		//runs case 1 in implementation file
	cout << "\n\n----------------------------------------------------" << endl;
	cout << "                        CASE 2                      " << endl;
	cout << "----------------------------------------------------" << endl;
	L.case2();		//runs case 2 in implementation file
	cout << "\n\n----------------------------------------------------" << endl;
	cout << "                        CASE 3                      " << endl;
	cout << "----------------------------------------------------" << endl;
	L.case3();		//runs case 3 in implementation file
	cout << "\n\n----------------------------------------------------" << endl;
	cout << "                        CASE 4                      " << endl;
	cout << "----------------------------------------------------" << endl;
	L.case4();		//runs case 4 in implementation file

	return 0;
}

