// =========================================================

//HW2P1 Binary Search
//Your name: Christopher Wendling
//Complier:  g++
//File type: Source file

//================================================================
#include <iostream>
using namespace std;

typedef int el_t;		//define our int type
const int MAX = 10;		//define our array MAX size

int binSearch(el_t a[], el_t, int, int);	//prototype declaration

int main(){
	//initialization of local variables
    el_t a[MAX] = {1,3,5,7,9,11,13,15,17,19};
	int first = 0, last = MAX - 1, result = -1;
	el_t x = 0;
	
	try{
		cout << "Enter a number to search for: ";
		cin >> x;
		cout << endl;

		result = binSearch(a, x, first, last);		//calls searching function
		cout << "Your value is in location: " << result + 1 << endl;	//prints index if found
	}
	catch(char const* error){		
		cerr << "***Error*** : " << error << endl;
		exit(1);
	}
		
	return 0;
} 

/*
Purpose: recursively finds a given value in an ordered list.
Param: int, array[], int userInput, int firstIndex, int lastIndex
Return: int index, where value was found. Else throws errors.
Created: 092013
*/
int binSearch(el_t a[], el_t x, int first, int last)
{
    if((x < a[0]) || (x > a[MAX - 1]))		//checks if value is in range of list boundries.
        throw "Value outside of list boundaries.";

    int mid = int(floor(first+last)/2);		//selects new middle index
	
	if(x == a[mid])			//if found returns index
		return mid;
	else if(first == last)		//stops search if user input was in range but not found.
		throw "Value not found.";
	else if(x < a[mid])		//if user input is on lower half then moves last down
		last = mid - 1;		
	else if(x > a[mid])		//if user input is on upper half moves first up
		first = mid + 1;
	return binSearch(a, x, first, last);	//recursively cuts list in half again
}
