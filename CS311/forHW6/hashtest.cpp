#ifndef HASH_C
#define HASH_C

// =========================================================

//HW6
//Your name: Christopher Wendling
//Complier:  g++
//File type: Dgraph Client file

//===========================================================
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>

using namespace std;

const int RUN = 350;
const int SIZE = 10;
const int MAX = 495;
const int iteration = 100000;

bool check(int m[][SIZE], int a[])
{
	for(int i = 0; i < RUN; ++i)
		for(int j = 0; j < SIZE; ++j)
			if(m[i][j] != a[j])
				return true;
			
	return false;
}

//------------------------------------------------------
int main()
{
	srand(time(0));
	
	int digit = 0;
	int count = 0;
	bool unique = false;
	
	int cust[RUN][SIZE];
	float stat[MAX];
	int store[MAX];
	int temp[SIZE];
	
	//initialize
	for(int i = 0; i < MAX; ++i){
		store[i] = 0;
		stat[i] = 0;
	}
	
	while(count != iteration){	//stores customer info
		for(int i = 0; i < RUN; ++i){
			unique = false;
			while(!unique){
				for(int j = 0; j < SIZE; ++j)
					temp[j] = rand() % 10 + 1;	//select random 
				
				unique = check(cust,temp);
			}
			for(int j = 0; j < SIZE; ++j){
				cust[i][j] = temp[j];
				digit += (cust[i][j] * (j + 1));
			}
			store[digit]++;
			digit = 0;
		}
		count++;
	}
	float t1 = 0;
	for(int i = 0; i < MAX; ++i){
		t1 = float(store[i]);
		t1 = t1/RUN;
		stat[i] = t1 * 100;
	}

	float v1 = stat[0];
	float v2 = 0, v3 = 0; 
	int loc1 = 0, loc2 = 0, loc3 = 0;
	
	for(int i = 0; i < MAX; ++i){
		if(stat[i] > v1){
			v1 = stat[i];
			loc1 = i;
		}
		else if((stat[i] < v1) && (stat[i] > v3)){
			v2 = stat[i];
			loc2 = i;
		}
		else if((stat[i] < v2) && (stat[i] > v3)){
			v3 = stat[i];
			loc3 = i;
		}
	}
	
	cout << "Top 3 percentages: " << endl;
	/*int loc1 = 0, loc2 = 0, loc3 = 0; 
	for(int i = 0; i < MAX; ++i){
		if(stat[i] > v1){
			v1 = stat[i];
			loc1 = i;
		}*/
	cout << "Index: " << loc1 << "\t" << fixed << setprecision(3) << stat[loc1] << endl;
	cout << "Index: " << loc2 << "\t" << fixed << setprecision(3) << stat[loc2] << endl;
	cout << "Index: " << loc3 << "\t" << fixed << setprecision(3) << stat[loc3] << endl;
	
	//cout << "Index: " << loc1 << "\t" << fixed << setprecision(3) << stat[loc] << endl;
	
	return 0;
}

#endif

