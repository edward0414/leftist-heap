
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
}

// You must implement everything
/****** Done ******/
template <typename Type>
Type Leftist_node<Type>::retrieve() const {
	return element;
};

/****** Done ******/
template <class Type>
Leftist_node<Type> *Leftist_node<Type>::left() const {
	return left_tree;
};

/****** Done ******/
template <class Type>
Leftist_node<Type> * Leftist_node<Type>::right() const {
	return right_tree;
};

/****** Done ******/
template <typename Type>
int Leftist_node<Type>::null_path_length() const { 
	if(heap_null_path_length == NULL){
		return -1;
	}
	else 
		return heap_null_path_length;
}

/****** Done ******/
template <typename Type>
void Leftist_node<Type>::clear() {
	if (element == NULL) {
		return;
	}

	Leftist_node left = &left_tree;
	left.clear();

	Leftist_node right = &right_tree;
	right.clear();

	delete *element;
}

template <typename Type>
int Leftist_node<Type>::count(Type const &obj) const {
	// TODO:
	// Return the number of instances of obj in this sub-tree.
	// You can do it recursively
	// or iteratively using stack/queue ;)
	
	return 0; //placeholder
}

template <typename Type>
void Leftist_node<Type>::push( Leftist_node<Type> *new_heap, Leftist_node<Type> *&ptr_to_this) {
	// TODO:
	//If the new_heap is null return
	//if this is null, set the pointer to this to be the new heap and return
	// If the element (value) of current node > new_heap’s element, set the pointer to this to be the new heap and push this node to the new heap
	//If the element of this node ≤  new_heap’s element, push the node into the right subree.
	// Update the null_path length 
	// if the left sub-tree has a smaller null_path_length than the right sub-tree, swap the two sub-trees

}

#endif
