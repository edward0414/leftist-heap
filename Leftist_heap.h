
/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  uwuserid @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter|Spring|Fall) 201N
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Leftist_node.h"

template <typename Type>
class Leftist_heap {
	private:
		Leftist_node<Type> *root_node;
		int heap_size;

	public:
		Leftist_heap(); //done
		~Leftist_heap(); //done

		void swap( Leftist_heap &heap ); //done
		

		bool empty() const; //done
		int size() const; //done
		int null_path_length() const;
		Type top() const;
		int count( Type const & ) const;

		void push( Type const & );
		Type pop();
		void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Leftist_heap<T> const & );
};

// some sample functions are given

template <typename Type>
Leftist_heap<Type>::Leftist_heap():
root_node( nullptr ),
heap_size( 0 ) {
	// does nothing
}



template <typename Type>
Leftist_heap<Type>::~Leftist_heap() {
	clear();  // might as well use it...
}

template <typename Type>
void Leftist_heap<Type>::swap( Leftist_heap<Type> &heap ) {
	std::swap( root_node, heap.root_node );
	std::swap( heap_size, heap.heap_size );
}




// Your implementation here
// STRONG HINT:  Write a default definition of each function, even if
// it only returns the default value (false, 0, or Type()).
//
// Once you have done this, you can proceed and implement the member functions
// one at a time.  If you do not, and just start implementing the member
// functions so that you can't compile and test your function, good luck. :-)


template <typename Type>
bool Leftist_heap<Type>::empty() const {
	return this->heap_size == 0;
}

template <typename Type>
int Leftist_heap<Type>::size() const {
	return this->heap_size;
}

template <typename Type>
int Leftist_heap<Type>::null_path_length() const {
	if(this->root_node == nullptr){
		return -1;
	}
	return this->root_node->null_path_length();
}

template <typename Type>
Type Leftist_heap<Type>::top() const {
	if (heap_size <= 0) {
		throw underflow();
	} else {
		return this->root_node->retrieve();
	}

}

template <typename Type>
int Leftist_heap<Type>::count(Type const &obj) const {
	// Return the number of instances of obj in the heap
	if(this->root_node == nullptr){
		return -1;
	}
	else 
		return this->root_node->count(obj);
}


template <typename Type>
void Leftist_heap<Type>::clear() {
	// Call clear on the root_node node
	// Reset the root node
	// Reset the heap size
	if(this->root_node == nullptr){
		this->root_node->clear();
	}

	this->heap_size = 0;
}


template <typename Type>
void Leftist_heap<Type>::push(Type const &obj) {
	// Create a new leftist node
	// Call push on the root node and pass the new node and root node as the arguments
	//Increament the heap size

	Leftist_node<Type>* new_node = new Leftist_node<Type>(obj);
	
	if(this->root_node == nullptr){
		this->root_node = new_node;
	}
	else{
	this->root_node->push(new_node, this->root_node);
	}

	this->heap_size ++;
}


template<typename Type>
Type Leftist_heap<Type>::pop() {
	// If the heap is empty throw underflow
	if (this->root_node == nullptr) {
		throw underflow();
	}

	// TODO:
	// Pop the last element and delete its node
	// The left sub-tree becomes the root node 
	// The right sub-tree is pushed into the new root node
	// Decrement the heap size 
	// Return the element of the popped node
	Leftist_node<Type> *l = this->root_node->left();
	Leftist_node<Type> *r = this->root_node->right();

	Type value = this->root_node->retrieve();

	delete this->root_node;
	this->root_node = l;
	this->root_node->push(r, this->root_node);

	this->heap_size = this->heap_size - 1;

	return value;
}


// You can modify this function however you want:  it will not be tested

template <typename T>
std::ostream &operator<<( std::ostream &out, Leftist_heap<T> const &heap ) {
	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
