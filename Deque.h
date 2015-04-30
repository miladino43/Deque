#ifndef _DEQUE_
#define _DEQUE_
#include <cstdlib>

#include <stdexcept>

using namespace std;
//Node class for the singly Linked list
template<class T>
class Node{
public:

	T data;
	Node<T>* next;

	
	// constructor
	Node(T x);
};
// Default constructor
// PARAM: x = the data of the node
// PRE:
// POST: Creates a node with data x and next value NULL
template<class T>
Node<T>::Node(T x){

data = x;
next = NULL;

}

template<class T>
class Deque{
public:

	// Default constructor
	// PARAM: 
	// PRE:
	// POST: Creates an empty Deque
	Deque();

	// Copy constructor
	// PARAM: dq is the deque to be assigned to the calling object
	// PRE:
	// POST: Creates an object that is a copy of dq
	Deque(const Deque & dq);

	// Destructor
	// PARAM:
	// PRE:
	// POST: Memory associated with deque is de-allocated
	~Deque();

	// Overloaded assignment operator
	// In dq1 = dq2 assigns dq2 to dq1 and returns dq1
	// PARAM: dq = deque to be assigned to the calling object
	// PRE:
	// POST: Copies ls to calling object, returns calling object
	Deque & operator=(const Deque &);

	// Inserts data in deque in from the front
	// PARAM: n = data to be inserted
	// PRE:
	// POST: n is inserted in order into deque
	void insert_front(T n);

	// Inserts data in deque in from the back
	// PARAM: n = data to be inserted
	// PRE:
	// POST: n is inserted in order into deque
	void insert_back(T n);

	// Removes node from the front of deque
	// PARAM: 
	// PRE:deque is not empty
	// POST: Removes front node from deque and return
	// data that was stored at that node
	T  remove_front();

	// Removes node from the back of deque
	// PARAM: 
	// PRE: deque is not empty
	// POST: Removes back node from deque and return
	// data that was stored at that node
	T  remove_back();

	// returns data stored at the front of deque
	// PARAM: 
	// PRE:deque is not empty
	// POST: return the data at the front node
	// throw exception if deque is empty
	T  peek_front()const;

	// returns data stored at the back of deque
	// PARAM: 
	// PRE:deque is not empty
	// POST: return the data at the back node
	// throw exception if deque is empty
	T  peek_back()const;

	// determines if deque is empty
	// PARAM: 
	// PRE:
	// POST: return the true if deque is empty
	// and false if deque is not empty
	bool empty()const;

	// determines total number of nodes in deque
	// PARAM: 
	// PRE:
	// POST: return number of nodes or Size of deque
	int size()const;
		
private:

	//pointer to front of deque
	Node<T>* front;
	//pointer to back of deque
	Node<T>* back;
	//number of nodes in deque
	int Size;
	
	// (HELPER METHOD)Makes a deep copy of a deque
	// PARAM: dq is the deque to copied
	// PRE: Calling object is empty
	// POST: deque contents are identical to dq
	void copyDeque(const Deque & dq);

	// (HELPER METHOD)Removes all the items from the deque and
	// deallocates dynamic memory associated with nodes
	// PARAM: 
	// PRE: 
	// POST: deque is empty
	void deleteDeque();
	
};

#include "Deque.cpp"

 

#endif