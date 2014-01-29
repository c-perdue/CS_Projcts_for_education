//================================================================

//HW2P2 Merge sort
//Your name: Christopher Wendling
//Complier:  g++
//File type: Source file
//Created: 092813

//================================================================
#include <iostream>
#include <vector>
using namespace std;

typedef int el_t;		//define our int type

//Prototypes
void combine(vector<el_t> A, vector<el_t> B, vector<el_t>& C);

int main(){

	vector<el_t> L1, L2, L3;	//declear 3 vectors
	int num1, num2;				//user input variables
	
	try{
		cout << "Enter a 3 digit # in ascending order: ";
		cin >> num1;
		cout << "\nEnter another 3 digit # in ascending order: ";
		cin >> num2;
		
		//This loop takes each digit of the user input and adds it
		//to the corresponding list.
		while((num1 >= 1) || (num2 >= 1)){
			if(L1.size() == 0 && L2.size() == 0){	//adds first digits into list
				L1.push_back(num1%10);			//can't use list.begin() without this first
				L2.push_back(num2%10);
			}
			else{			//adds the remainder of the digits into our lists
				L1.insert(L1.begin(), (num1%10));	//stores each digit in front of list
				L2.insert(L2.begin(), num2%10);
			}
			num1 /= 10;		//truncates the last digit of each variable
			num2 /= 10;
		}
		
		combine(L1, L2, L3);	//calls function to combine our list
								//L3 is pass by reference
		
		//prints our final result
		cout << "\nYour combined list is: \n[";
		for(int i = 0; i < L3.size(); ++i){
			cout << L3[i];
			if(i != (L3.size()-1))
				cout << ", ";
		}
		cout << "]" << endl;
	}
	catch(char const* error){		//general error catching if desired
		cerr << "***Error*** : " << error << endl;
		exit(1);
	}
	return 0;
}

/*
Purpose: To combine two lists of ascending order into one list of ascending order.
Param: Three vectors of type el_t, last vector passed by reference.
Modified: 093013
*/
void combine(vector<el_t> A, vector<el_t> B, vector<el_t>& C)
{
	int ia = 0, ib = 0;		//initialize indexing variables
	
	while((A.size() != ia) && (B.size() != ib)){	//compares numbers until one list has no more to compare
		if(A[ia] < B[ib])
			C.push_back(A[ia++]);	//appends to result list and increments A's index
		else
			C.push_back(B[ib++]);	//appends to result list and increments B's index
			
		cout << "Comparison!" << endl;
	}
	if(ia != A.size())		//if index is not at A.size() we add the rest of A to results
		for(ia; ia < A.size(); ++ia)
			C.push_back(A[ia]);
	else if(ib != B.size())	//if index is not at B.size() we add the rest of B to results
		for(ib; ib < B.size(); ++ib)
			C.push_back(B[ib]);
}