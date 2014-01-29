/*
// ====================================================

HW3P1 link list
Your name: Christopher Wendling
Complier:  g++
File type: implementation file

//=====================================================
*/

#include"llist.h" 

//Purpose: Constructor, will initialize all variables in class.
llist::llist()
{
	front = rear = NULL;	//set pointer to safe memory location
	count = 0;		//set counter to zero
}
//-------------------------------------------------------------------
//Purpose: Destructor, will delete remaining Nodes at end of object scope
llist::~llist()
{
	el_t oldNum;	//element to hold old number before deletion 

	//cout << endl;
	while(!isEmpty()){		//loops until list is empty
		deleteFront(oldNum);	//deletes front Node and return the old number
		//cout << "***Deleting Node Number***: " << oldNum << endl;
	}
	//cout << "List destroyed." << endl;
}
//-------------------------------------------------------------------
//Purpose: To check is list is empty or not
//Return: true if empty and false if not empty
//Modified: 100213
bool llist::isEmpty()
{
	if((front == NULL) && (rear == NULL))	//checks if class pointers are pointing to NULL space
		return true;
	else
		return false;
}
//-------------------------------------------------------------------
//Purpose: To display the entire list.
//Modified: 100213
void llist::displayAll()
{
	if(isEmpty())	//if list is empty display error.
		cout << "This list is empty, nothing to display.";
	else{		//otherwise display list
		nodeptr p = front;		//Node pointer set at front of list
		cout << "[" << p->elem;	//print first element
		p = p->next;		//increment pointer
		while(p != NULL){	//loop until pointer is at NULL
			cout << ", ";
			cout << p->elem;
			p = p->next;	//increment pointer
		}
		cout << "]";
	}
}
//-------------------------------------------------------------------
//Purpose: Adds new element to back of list.
//Param: new element from user
//Modified: 100213
void llist::addRear(el_t newNum)
{
	nodeptr p = new Node;	//Node pointer to new Node
	
	if(isEmpty()){		//when list is empty adds Node
		p->elem = newNum;	//sets new Node element
		p->next = NULL;		//sets new Node's next pointer
		front = p;		//set front pointer to new Node
		rear = p;		//set rear pointer to new Node
		count++;		//increment counter
	}
	else{		//when not empty adds to rear
		rear->next = p;		//sets last Node's next pointer to new Node
		p->elem = newNum;	
		p->next = NULL;
		rear = p;		//set rear pointer to new Node
		count++;		//increment counter
	}
}
//-------------------------------------------------------------------
//Purpose: To delete the first Node in the list.
//Param: element passed by reference to hold the old element.
//Modified: 100213 
void llist::deleteFront(el_t& oldNum)
{
	if(isEmpty())	//when empty will throw error
		throw UnderFlow();
	else{		//otherwise delete Node
		nodeptr p = front;		//Node pointer set to first Node
		oldNum = p->elem;		//stores old element, passes back by reference
		p = front->next;		//set pointer to second Node
		delete front;
		front = p;			//set front pointer to new first Node
		count--;		//decrement counter
		if(front == NULL)	//If that was the last node then set rear to NULL also
			rear = NULL;
	}
}
//-------------------------------------------------------------------
//Purpose: To add a new Node at front of list
//Param: new element from user
//Modified: 100213
void llist::addFront(el_t newNum)
{
	if(isEmpty())	//when empty call add to rear
		addRear(newNum);
	else{		//otherwise adds new Node
		nodeptr p = new Node;	//Node pointer set to a new Node
		p->next = front;	//sets new Node's next pointer to front of list
		p->elem = newNum;
		front = p;		//moves front pointer to new Node
		count++;
	}	
}
//-------------------------------------------------------------------
//Purpose: To delete the last element in the list.
//Param: element passed by reference to hold the old element.
//Modified: 100413
void llist::deleteRear(el_t& oldNum)
{
	if(isEmpty())	//when empty throw error
		throw UnderFlow();
	else if(front == rear)	//when only one Node exists delete from front
		deleteFront(oldNum);
	else{		//otherwise find last node and delete it
		nodeptr p = front;		//Node pointer set to front of list
		oldNum = rear->elem;	//store old element, passes back by reference
		while(p->next != rear)	//loops until at second to last Node
			p = p->next;
		delete rear;
		rear = p;		//moves rear pointer to p pointer location
		p->next = NULL;		//sets rear Node's next pointer to NULL space
		count--;		//decrements counter
	}		
}
//-------------------------------------------------------------------
//Purpose: To delete the requested Node in the list
//Param: int index of Node to delete, and element passed by reference 
//Modified: 100413
void llist::deleteIth(int i, el_t& oldNum)
{
	if(i < 1 || i > count)	//when i is not in list throw error
		throw OutOfRange();
	else if(i == 1)		//when i is first Node call delete front
		deleteFront(oldNum);
	else if(i == count)		//when i is the last Node call delete rear
		deleteRear(oldNum);
	else{		//Otherwise delete requested Node
		nodeptr p = front, q = front->next;	//pointer p set to first Node, and pointer q set to second Node
		for(int j = 2; j <= i; ++j){	//loops to requested Node
			if(i == j){		//when we reach requested Node, delete
				p->next = q->next;		//set node's next before i to node after i
				oldNum = q->elem;		//store old element
				delete q;
				count--;
			}
			else{
				p = p->next;		//moves p to next node
				q = q->next;		//moves q to next node
			}
		}
	}			
}
//-------------------------------------------------------------------
//Purpose: To add a new Node before requested Node location
//Param: int index of Node to add before, and new element from user
//Modified: 100413
void llist::addBeforeIth(int i, el_t newNum)
{
	if(i < 1 || i > count + 1)	//when i is not in list's range throw error
		throw OutOfRange();
	else if(i == 1)		//when i is the first Node call add to front
		addFront(newNum);
	else if(i == count + 1)	//when i is the last Node + 1 call add to rear
		addRear(newNum);
	else{		//otherwise find requested Node and add before it
		nodeptr p = front, q = front->next, k = new Node;	//p points to first Node, q points to second Node, and k points to a new Node
		for(int j = 2; j <= i; ++j){	//loops to requested Node
			if(i == j){		//when at requested Node add new Node before it
				k->next = q;	//connects new Node to Ith node
				p->next = k;	//connects Ith - 1 Node to new Node
				k->elem = newNum;
				count++;
			}
			else{
				p = p->next;
				q = q->next;
			}
		}
	}
}
//-------------------------------------------------------------------
//Purpose: Run the requested case events to save time
//Modified: 100513
void llist::case1()
{
	el_t oldNum;	//holds old elements when passed back by reference
	
	if(isEmpty())	//when empty, prints empty
		cout << "This list is empty." << endl;
	else		//otherwise prints not empty
		cout << "There are items in this list." << endl;
		
	displayAll();
	addRear(1);
	addRear(2);
	addRear(3);
	displayAll();
	deleteFront(oldNum);
	cout << "You have removed the number " << oldNum << endl;
	deleteFront(oldNum);
	cout << "You have removed the number " << oldNum << endl;
	displayAll();
	
	if(isEmpty())	//when empty prints empty
		cout << "This list is empty." << endl;
	else		//otherwise prints not empty
		cout << "There are items in this list." << endl;
		
	deleteFront(oldNum);
	cout << "You have removed the number " << oldNum << endl;
	
	if(isEmpty())	//when empty prints empty
		cout << "This list is empty." << endl;
	else		//otherwise print not empty
		cout << "There are items in this list." << endl;
}
//-------------------------------------------------------------------
//Purpose: To run requested case to save time
//Modified: 100513
void llist::case2()
{
	el_t oldNum;	//holds old element when passed back by reference
	bool error = false;		//used for when errors occur for if statements after ward
	
	addFront(5);
	addFront(4);
	deleteFront(oldNum);
	cout << "You have removed the number " << oldNum << endl;
	addRear(6);
	addRear(8);
	addRear(9);
	displayAll();
	addBeforeIth(1,4);
	addBeforeIth(4,7);
	addBeforeIth(7,10);
	try{
		addBeforeIth(9,12);
	}
	catch(llist::OutOfRange){
		cerr << "***Error***: Item requested not in range of list." << endl;
	}
	try{
		addBeforeIth(0,0);
	}
	catch(llist::OutOfRange){
		cerr << "***Error***: Item requested not in range of list." << endl;
	}
	displayAll();
	deleteIth(1,oldNum);
	cout << "You have removed the number " << oldNum << endl;
	deleteIth(6,oldNum);
	cout << "You have removed the number " << oldNum << endl;
	deleteIth(3,oldNum);
	cout << "You have removed the number " << oldNum << endl;
	try{
		deleteIth(5,oldNum);
	}
	catch(llist::OutOfRange){
		error = true;
		cerr << "***Error***: Item requested not in range of list." << endl;
	}
	if(error == false)	//when no errors print this
		cout << "You have removed the number " << oldNum << endl;
	else		//otherwise reset error to false
		error = false;
	try{
		deleteIth(0,oldNum);
	}
	catch(llist::OutOfRange){
		error = true;
		cerr << "***Error***: Item requested not in range of list." << endl;
	}
	if(error == false)		//when no errors prints this
		cout << "You have removed the number " << oldNum << endl;
	displayAll();
	while(count != 0){	//loops until all Nodes are deleted
		deleteRear(oldNum);
		cout << "You have removed the number " << oldNum << endl;
	}
	displayAll();
}
//-------------------------------------------------------------------
//Purpose: To run requested case to save time
//Modified: 100513
void llist::case3()
{
	el_t oldNum;	//holds old element when passed back by reference
	bool error = false; //updates when errors are found from printing after ward
	
	try{
		addBeforeIth(0,0);
	}
	catch(llist::OutOfRange){
		cerr << "***Error***: Item requested not in range of list." << endl;
	}
	try{
		deleteFront(oldNum);
	}
	catch(llist::UnderFlow){
		error = true;
		cerr << "***Error***: No items in list." << endl;
	}
	if(error == false)		//when no errors print this
		cout << "You have removed the number " << oldNum << endl;
}
//-------------------------------------------------------------------
//Purpose: To run case to save time
//Modified: 100513
void llist::case4()
{
	el_t oldNum;		//holds old element passed back by reference
	bool error = false;		//updates when errors are found
	
	try{
		deleteIth(2,oldNum);
	}
	catch(llist::OutOfRange){
		error = true;
		cerr << "***Error***: Item requested not in range of list." << endl;
	}
	if(error == false)	//when no errors are found prints this
		cout << "You have removed the number " << oldNum << endl;
	else		//otherwise reset error to false
		error = false;
		
	try{
		deleteRear(oldNum);
	}
	catch(llist::UnderFlow){
		error = true;
		cerr << "***Error***: No items in list." << endl;
	}
	if(error == false)		//when no errors found print this
		cout << "You have removed the number " << oldNum << endl;
}

