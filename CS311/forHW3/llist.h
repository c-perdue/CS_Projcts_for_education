#ifndef LLIST_H
#define LLIST_H
/*
// ====================================================

HW3P1 link list
Your name: Christopher Wendling
Complier:  g++
File type: header file

//=====================================================
*/
#include <iostream>
using namespace std;

struct Node;		//prototype so we can type define a pointer
typedef int el_t ;
typedef Node* nodeptr;		//pointer variable 
	   
struct Node		// list node is defined here as a struct Node
{
  el_t elem;   // elem is the element stored
  nodeptr next;  // next is the pointer to the next node
};

class llist
{
 protected:
  nodeptr front;     // front  pointer 
  nodeptr rear;      // rear   pointer
  int  count;        // counter for the number of elements
  
 public:
  class UnderFlow{};
  class OutOfRange{};
    
  llist();             // constructor  
  ~llist();            // destructor
  
  //Purpose: To check if list is empty or not.
  bool isEmpty();
  
  //Purpose: To display entire list.
  void displayAll();
  
  //How to call: Pass element to add into new Node.
  //Purpose: Adds a Node to the back of the list.
  void addRear(el_t newNum);
  
  //How to call: declare the variable to get the old value by reference.
  //Purpose: To delete the first Node in the list.
  void deleteFront(el_t& oldNum);
  
  //How to call: Pass element to add into new Node.
  //Purpose: To add a new Node into the front of the list.
  void addFront(el_t newNum);
    
  //How to call: declare the variable to get the old value by reference.
  //Purpose: To delete the last Node in the list.
  void deleteRear(el_t& oldNum);
  
  //How to call: Pass the index of requested Node to delete 
  //and declare the variable to get the old value by reference.
  //Purpose: To delete the requested Node in the list.  
  void deleteIth(int i, el_t& oldNum);
  
  //How to call: Pass the index of the Node to add before  
  //and pass the new element to be added into new Node.
  //Purpose: To add a new Node in the middle of your list.  
  void addBeforeIth(int i, el_t newNum);
  
  //Cases to run and test program.
  void case1();
  void case2();
  void case3();
  void case4();  
};
#endif


