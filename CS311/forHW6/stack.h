#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =======================================================

// HW1P2 stack(vector)
// Your name: Christopher Wendling
// Compiler:  g++ 
// File type: headher file stack.h

//=======================================================

typedef char el_t;      // the el_t type is int for now
                      // el_t is unknown to the client
class stack
  { 

   private: // to be hidden from the client

        vector<el_t> el;       // el is a vector of el_t's

   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: Enters an element at the top;
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);

        // HOW TO CALL: pass object to find top element
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);

        // ************ add good comments for each function *****
      	bool isEmpty();		//checks if stack is empty
      	bool isFull();		//checks if stack is full
        void displayAll();	//prints all elements in stack
        void clearIt();		//destroys all elements of stack
        
  };  

// Note: semicolon is needed at the end of the header file

