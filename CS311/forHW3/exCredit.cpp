#ifndef EXCREDIT_C
#define EXCREDIT_C
/*
// ====================================================

HW3P3	Extra Credit
Your name: Christopher Wendling
Complier:  g++
File type: client file

//=====================================================
*/
#include "slist.h"

int main()
{
	slist L3, L4;	//declares two new slist objects
	int oldNum;		//holds old elements after deletion
	
	cout << endl << "----------------------------------------------------------" << endl;
	cout << "-                       Extra Credit!                    -" << endl;
	cout << "----------------------------------------------------------" << endl;
	
	//case #1
	cout << "\nTesting L3 empty and L4 empty..." << endl;
	if(L3 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	//case #2
	L4.addRear(1);
	L4.addRear(2);
	cout << "\nTesting L3 is empty and L4 has 2 elements..." << endl;
	if(L3 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	//case #3
	L4.deleteRear(oldNum);
	L4.deleteRear(oldNum);
	L3.addRear(1);
	L3.addRear(2);
	cout << "\nTesting L3 has 2 elements and L4 is empty..." << endl;
	if(L3 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	//case #4
	L3.addRear(3);
	L4 = L3;
	cout << "\nTesting L3 has 1,2,3 and L4 has 1,2,3..." << endl;
	if(L3 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	//case #5
	L4.deleteRear(oldNum);
	cout << "\nTesting L3 has 1,2,3 and L4 has 1,2..." << endl;
	if(L3 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	//case #6
	L4 = L3;
	L4.addRear(4);
	cout << "\nTesting L3 has 1,2,3 and L4 has 1,2,3,4..." << endl;
	if(L3 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	//case #7
	L4.deleteIth(3,oldNum);
	cout << "\nTesting L3 has 1,2,3 and L4 has 1,2,4..." << endl;
	if(L3 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
		
	//added this since we never really tested it yet....
	cout << endl << "\n----------------------------------------------------------" << endl;
	cout << "-                 Copy Constructor tests                 -" << endl;
	cout << "----------------------------------------------------------" << endl;
	
	//case #8
	slist L5(L4);		//declare new slist object and copying L4 into it
	cout << "\nTesting L5 created using L4..." << endl;
	if(L5 == L4)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	//case #9
	L5.deleteRear(oldNum);
	L5.deleteRear(oldNum);
	L5.deleteRear(oldNum);
	cout << "\nClearing L5..." << endl;
	L5.displayAll();
	slist L6(L5);		//declaring new slist object using empty list L5
	cout << "\nTesting L6 created using empty list L5..." << endl;
	if(L5 == L6)	//when both objects are equal...
		cout << "They are equal!" << endl;
	else			//otherwise say they are Not equal
		cout << "They do NOT equal each other!" << endl;
		
	return 0;
}
#endif

