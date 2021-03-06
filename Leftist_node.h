
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

#ifndef LEFTIST_NODE_H
#define LEFTIST_NODE_H

#include <algorithm>
// You may use std::swap and std::min
#include <iostream>

#ifndef nullptr
#define nullptr 0
#endif

template <typename Type>
class Leftist_node {
	private:
		Type element;
		Leftist_node *left_tree;
		Leftist_node *right_tree;
		int heap_null_path_length;

	public:
		Leftist_node( Type const & );

		Type retrieve() const;
		bool empty() const;
		Leftist_node *left() const;
		Leftist_node *right() const;
		int count( Type const & ) const;
		int null_path_length() const;

		void push( Leftist_node *, Leftist_node *& );
		void clear();
};

template <typename Type>
Leftist_node<Type>::Leftist_node( Type const &obj ):
element( obj ),
left_tree( nullptr ),
right_tree( nullptr ),
heap_null_path_length( 0 ) {
	// does nothing
}

// You may need this

template <typename Type>
bool Leftist_node<Type>::empty() const {
	return ( this == nullptr );
	//checks if the node is empty
}

template <typename Type>
Type Leftist_node<Type>::retrieve() const {
//Return the element.
	return this->element;
}

template <class Type>
Leftist_node<Type> *Leftist_node<Type>::left() const {
// Return the address of left tree of this node
	return this->left_tree;
}

template <class Type>
Leftist_node<Type> *Leftist_node<Type>::right() const {
// Return the address of right tree of this node
	return this->right_tree;
}

template <typename Type>
int Leftist_node<Type>::count(Type const &obj) const {
// Return the number of instances of obj in this sub-tree.
// You can do it recursively
	int counter = 0;		//Initialize counter
	
	if(this->left() != nullptr){
		counter = counter + this->left_tree->count(obj); 	//Recursive call to count for the left tree as long as it's not null
	}
	if(this->right() != nullptr){
		counter = counter + this->right_tree->count(obj);	//Recursive call similar for right tree
	}
	if(this->element == obj){
		counter++;		//Incrementing counter if the element in the node is equal to the object
	}

	if(empty()){		//If there are no elements, return 0 for counter
		return 0;
	}
	return counter;

}

template <typename Type>
int Leftist_node<Type>::null_path_length() const {
// Return the member variable null-path length unless this is the null pointer, in which case, return -1.
	if(this == nullptr){
		return -1;
	}
	else 
		return this->heap_null_path_length;
}

template <typename Type>
void Leftist_node<Type>::push(Leftist_node *new_heap, Leftist_node *&ptr_to_this)  {
//If the new_heap is null return
//if this is null, set the pointer to this to be the new heap and return
// If the element (value) of current node > new_heap’s element, set the pointer to this to be the new heap and push this node to the new heap
//If the element of this node ≤  new_heap’s element, push the node into the right subree.
// Update the null_path length 
// if the left sub-tree has a smaller null_path_length than the right sub-tree, swap the two sub-trees
	if(new_heap == nullptr){
		//std::cout << "ret 1, " << std::endl << std::flush;
		return;							//If the new_heap is a nullptr, do nothing and return
	}
	
	if(empty()){
		//std::cout << "ret 2, " << new_heap->retrieve() << std::endl << std::flush;
		ptr_to_this = new_heap;			//If heap is empty, set the new heap to ptr_to_this
		return;
	}


	if(this->retrieve() <= new_heap->retrieve()){		//Element of this node ≤  new_heap’s element)
		//std::cout << "ret 3, " << new_heap->retrieve() << std::endl << std::flush;
		/*if(this->right() != nullptr){
				right()->push(new_heap, right_tree);
		}
		else {
				this->right_tree = new_heap;
		}*/

		this->right_tree->push(new_heap, this->right_tree);	//Push the node into the right subree.

		int npl_left = -1;
		int npl_right = -1;

		if(this->left() != nullptr){
			npl_left =  left()->null_path_length();
		}
		if(this->right() != nullptr){
			npl_right =  right()->null_path_length();
		}
		
		int m = npl_left;
	
		if(m > npl_right){
			m = npl_right;
		}

		this->heap_null_path_length = 1+m;


		if(npl_left < npl_right){
			Leftist_node<Type> * temp = this->left_tree;
			this->left_tree =  this->right_tree;
			this->right_tree = temp;
		}
		//std::cout << "setting new npl to: " << this->heap_null_path_length << std::endl << std::flush;
	}
	else{
		//std::cout << "ret 4, " << new_heap->retrieve() << std::endl << std::flush;
		ptr_to_this = new_heap;
		new_heap->push(this, new_heap);
		return;
	}
}

template<typename Type>
void Leftist_node<Type>::clear() {
//If new heap is null return
// Call clear function on the left sub-tree
// Call clear function on the right sub-tree
// Delete this node
	if(empty()){
		return;
	}
	this->left_tree->clear();
	this->right_tree->clear();

	delete this;
}


// You must implement everything

#endif
