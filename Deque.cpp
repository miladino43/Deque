#ifdef _DEQUE_
//#include"Deque.h"
#include <stdexcept>

// Default constructor
// PARAM: 
// PRE:
// POST: Creates an empty Deque
template <class T>
Deque<T>::Deque(){
	front = NULL;
	back = NULL;
	Size = 0;

}
// Copy constructor
// PARAM: dq is the deque to be assigned to the calling object
// PRE:
// POST: Creates an object that is a copy of dq
template <class T>
Deque<T>::Deque(const Deque & dq){
	copyDeque(dq);
}
// Destructor
// PARAM:
// PRE:
// POST: Memory associated with deque is de-allocated
template <class T>
Deque<T>::~Deque(){
	deleteDeque();
}
// Overloaded assignment operator
// In dq1 = dq2 assigns dq2 to dq1 and returns dq1
// PARAM: dq = deque to be assigned to the calling object
// PRE:
// POST: Copies ls to calling object, returns calling object
template <class T>
Deque<T> & Deque<T>::operator=(const Deque & dq){
	
	// Only copy the deque if it is a different object
	// The this pointer is the address of the calling object
	// i.e. if(calling object is not the parameter)
	if(this != &dq){
		deleteDeque(); //deallocate dynamic memory
		copyDeque(dq); //build new deque
	}
	return *this; //dereference pointer
}
// Inserts data in deque in from the front
// PARAM: n = data to be inserted
// PRE:
// POST: n is inserted in order into deque
template <class T>
void Deque<T>::insert_front(T n){
	//temporary pointer to store new node
	Node<T>* temp = new Node<T>(n);

		if(empty()){
		//back becoms new node
			back = temp;
		}
		//temp pointer's next points to front
		else {
			temp->next = front;	
		}
	//front should become the temp pointer
	front = temp;
	//temp node should not point to same thing as front
	temp = NULL;
	//deallocate memory
	delete temp;
	Size++;

}
// Inserts data in deque in from the back
// PARAM: n = data to be inserted
// PRE:
// POST: n is inserted in order into deque
template <class T>
void Deque<T>::insert_back(T n){
	//temporary pointer to store new node
	Node<T>* temp = new Node<T>(n);
	
		if(empty()){
			//front becomes new node
			front = temp;		
		}
		else {
			//backs next pointer points to temp node
			back->next = temp;
		}
	//back becomes the temp node
	back = temp;
	//temp pointer should not point to same thing as back
	temp = NULL;
	//deallocate memory
	delete temp;
	Size++;
}
// Removes node from the front of deque
// PARAM: 
// PRE:Deque should not be empty
// POST: Removes front node from deque and return
// data that was stored at that node
template <class T>
T  Deque<T>::remove_front (){
	//temporary node 
	Node<T> * temp;
		
		if(empty()){
			throw runtime_error("Deque is empty");
		}
	//point to front node
	temp = front;
	//front points to its next node
	front = front->next;

		//if we just removed last node set back to null	
		if (front == NULL){
			back = NULL;
		}
	//store the value of front node
	T tempData = temp->data;
	//remove the connection to the new front
	temp->next = NULL;
	//deallocate temp
	delete temp;

	Size--;
	return tempData;
	
}
// Removes node from the back of deque
// PARAM: 
// PRE:Deque should not be empty
// POST: Removes back node from deque and return
// data that was stored at that node
template <class T>
T  Deque<T>::remove_back(){
	//temporary node
	Node<T> * temp;
		
		if(empty()){
			throw runtime_error("Deque is empty");
		}
	//store back nodes value
	T backData = back->data;
	//temp node points to front node
	temp = front;
	//make sure mode than one node in deque
	if (temp->next != NULL){
		//travel down the deque until we are at node before back node
		while(temp->next != back){
			temp = temp->next;
		
		}
	//disconnet from back node
	temp->next = NULL;
	//deallocate memory
	delete back;
	//new back is the temp node
	back = temp;
	//disconnect and deallocate temp
	temp = NULL;
	delete temp;

	}//end if
		else{
		//handle removal if only one node
		temp = NULL;
		delete temp;
		front = NULL;
		back = NULL;
	
		}//end else

	Size--;
	return backData;
}
// returns data stored at the front of deque
// PARAM: 
// PRE: deque is not empty
// POST: return the data at the front node
// throw exception if deque is empty
template <class T>
T  Deque<T>::peek_front()const{
		if (front == NULL){

		throw runtime_error("Deque is empty");
	}
	return front->data;
}
// returns data stored at the back of deque
// PARAM: 
// PRE: deque is not empty
// POST: return the data at the back node
// throw exception if deque is empty
template <class T>
T  Deque<T>::peek_back()const{
	if (back == NULL){

		throw runtime_error("Deque is empty");
	}
	return back->data;
}
// determines if deque is empty
// PARAM: 
// PRE:
// POST: return the true if deque is empty
// and false if deque is not empty
template <class T>
bool Deque<T>::empty()const{
	//empty if fron and back both point to null
	if(front==NULL && back==NULL){
		return true;
	}
	else{
		return false;
	}

}
// determines total number of nodes in deque
// PARAM: 
// PRE:
// POST: return number of nodes or Size of deque
template <class T>
int Deque<T>::size()const{

	return Size;
}
// (HELPER METHOD)Makes a deep copy of a deque
// PARAM: dq is the deque to copied
// PRE: Calling object is empty
// POST: deque contents are identical to dq
template <class T>
void Deque<T>::copyDeque(const Deque & dq){
	front = NULL;
	back = NULL;
	Size = dq.Size;
	// Only make a copy if st is non-empty
		if(dq.front != NULL){
			// Make a copy of the parameter
			Node<T>* original = dq.front;
			Node<T>* copy;
			// First copy the front
			copy = new Node<T>(original->data);
			front = copy;
			original = original->next;

		// Now copy the rest of the deque
			while(original != NULL){
				copy->next = new Node<T>(original->data);
				copy = copy->next;
				original = original->next;
			}
			back = copy;
		}//end if

}
// (HELPER METHOD)Removes all the items from the deque and
// deallocates dynamic memory associated with nodes
// PARAM: 
// PRE: deque is not empty
// POST: deque is empty
template <class T>
void Deque<T>::deleteDeque(){
	//delete only if not empty
	if (!empty()){
		Node<T>* temp = front;
	

	// Iterate through deque deleting Nodes
		while(temp != NULL){
			temp = front->next;
		
			delete front;
			front = temp;
		}
		back = NULL;
	}//end if
	
}


#endif