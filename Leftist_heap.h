
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
		Leftist_heap();
		~Leftist_heap();

		void swap( Leftist_heap &heap );
		

		bool empty() const;
		int size() const;
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

template <typename Type>
bool Leftist_heap<Type>::empty() const{
	// Check if the heap is empty 
	if(this->heap_size <= 0){
		return true;
	}
	else 
		return false;
}

template<typename Type>
int Leftist_heap<Type>::size() const{
	// Return the number of nodes in the heap
	return this->heap_size;
}

template<typename Type>
int Leftist_heap<Type>::null_path_length() const {
// Return the heap_null_path_length of the root node
	if(this->root_node == nullptr){
		return -1;
	}
	else 
		return this->root_node->null_path_length();
}

template<typename Type>
Type Leftist_heap<Type>::top() const{
// If the heap is empty throw underflow 
// Otherwise, return the element of the root node
	if(this->heap_size <= 0){
		throw underflow();
	}
	return this->root_node->retrieve();
}

template<typename Type>
int Leftist_heap<Type>::count(Type const &obj) const {
// Return the number of instances of obj in the heap
	if(this->root_node == nullptr){
		return 0;
	}
	return this->root_node->count(obj);
}

template<typename Type>
void Leftist_heap<Type>::clear() {
// Call clear on the root node
// Reset the root node
// Reset the heap size
	this->root_node->clear();
	this->root_node = nullptr;

	this->heap_size = 0;
}

template<typename Type>
void Leftist_heap<Type>::push(Type const &obj) {
// Create a new leftist node
// Call push on the root node and pass the new node and root node as the arguments
//Increament the heap size
	Leftist_node<Type>* newNode = new Leftist_node<Type>(obj);

	if(this->root_node == nullptr){
		this->root_node = newNode;
	}
	else{
		this->root_node->push(newNode, this->root_node);
	}
	

	this->heap_size++;
}

template<typename Type>
Type Leftist_heap<Type>::pop() {
// If the heap is empty throw underflow
// Pop the last element and delete its node
// The left sub-tree becomes the root node 
// The right sub-tree is pushed into the new root node
// Decrement the heap size 
// Return the element of the popped node
	if(empty()){
		throw underflow();
	}

	Type value = root_node->retrieve();

	Leftist_node<Type>* original = root_node;

	root_node = root_node->left();

	//Leftist_node<Type>* right = root_node->right();

	root_node->push(original->right(), root_node);

	delete original;

	heap_size--;

	return value;
}


template <typename T>
std::ostream &operator<<( std::ostream &out, Leftist_heap<T> const &heap ) {
	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
