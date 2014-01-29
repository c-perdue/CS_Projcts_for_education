// =========================================================

//HW1P1 stack client
//Your name: Christopher Wendling
//Complier:  g++
//File type: client run file

//================================================================

#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"
using namespace std;

int main()
{
	stack postfixstack;  // integer stack
	string expression = " ";
	  
	cout << "type a postfix expression: " ;
	cin >> expression;
	  
	int i = 0;  // character position within expression
	char item;
	  
	int box1;  // receive things from pop
	int box2;  // receive things from pop
	  
	while(expression[i] != '\0'){
		try{
		  item = expression[i];    
			if(isdigit(item)){		//check if item is a number
			  box1 = int(item) - 48;     //type case number to int
				postfixstack.push(box1);
			}		  
			else if((item == '+') || (item == '-') || (item == '*')){
			    postfixstack.pop(box1);
				postfixstack.pop(box2);
				// a whole bunch of cases
				if(item == '-') 
					postfixstack.push(box2-box1);
				else if(item == '+')
					postfixstack.push(box1+box2);
				else if(item == '*')
					postfixstack.push(box1*box2);
					// also do the + and * cases 
					// push the result
			}
			else 
				throw "invalid item";
		} // this closes try
		  
		  // Catch exceptions and report problems and quit the program now. 
		catch(stack::Overflow){
		  cerr << "***Stack Overflow*** : Ending program." << endl;
			exit(1);
		}
		catch(stack::Underflow){
		  cerr << "***Stack Underflow*** : Ending program." << endl;
			exit(1);
		}
		catch(char const* errorcode){
		  cerr << "***Invalid Item*** : Ending program." << endl;
			exit(1);
		}
		// go back to the loop
		//postfixstack.displayAll();
		++i;
		
	}// end of while
	  
	  //  After the loop successfully completes: 
	  //  The result will be at the top of the stack. Pop it and show it.
	  //  If anything is left on the stack, an incomplete expression was found
	  // inform the user.
	postfixstack.pop(box1);
	if(!postfixstack.isEmpty()){	//if numbers remain cout error msg
	  cerr << "***Incomplete Expression*** : Ending program." << endl;
		exit(1);
	}
	else
		cout << "\nAnswer: " << box1 << endl;

	return 0;    
}
