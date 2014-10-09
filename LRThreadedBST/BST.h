// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This file includes all of the pieces of the BST implementation

// Include the node implementation
#include "BSTNode.h"
#include "BinNode.h"
// Include the dictionary ADT
#include "dictionary.h"
#include <stddef.h>
#include <iostream>

#ifndef BST_H
#define BST_H

using namespace std;

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key,E> {
private:
	BSTNode<Key,E>* root;   // Root of the BST
	BSTNode<Key, E>* current;
  
	int nodecount;         // Number of nodes in the BST

	// Private "helper" functions
	void clearhelp(BSTNode<Key, E>*);
	BSTNode<Key,E>* inserthelp(BSTNode<Key, E>*,
								const Key&, const E&);
	BSTNode<Key,E>* deletemin(BSTNode<Key, E>*);
	BSTNode<Key,E>* getmin(BSTNode<Key, E>*);
	BSTNode<Key,E>* removehelp(BSTNode<Key, E>*, const Key&);
	E* findhelp(BSTNode<Key, E>*, const Key&) const;
	void printhelp(BSTNode<Key, E>*, int) const;
	//void printhelp() const;
	void vist(BSTNode<Key, E>*) const;

public:
	BST() { root = NULL; nodecount = 0; }  // Constructor
	~BST() { clearhelp(root); }            // Destructor
	void printInOrder() const;
	void printReverseOrder() const;

	void clear()   // Reinitialize tree
		{ clearhelp(root); root = NULL; nodecount = 0; }

	// Insert a record into the tree.
	// k Key value of the record.
	// e The record to insert.
	void insert(const Key& k, const E& e) {
	if (nodecount == 0) {
		root = inserthelp(root, k, e);
	}
	else {
		current = inserthelp(root, k, e);
	}
	nodecount++;
	}

	// Remove a record from the tree.
	// k Key value of record to remove.
	// Return: The record removed, or NULL if there is none.
	E* remove(const Key& k) {
	E* temp = findhelp(root, k);   // First find it
	if (temp != NULL) {
		root = removehelp(root, k);
		nodecount--;
	}
	return temp;
	}
	// Remove and return the root node from the dictionary.
	// Return: The record removed, null if tree is empty.
	E* removeAny() {  // Delete min value
	if (root != NULL) {
		E* temp = new E;
		*temp = root->element();
		root = removehelp(root, root->key());
		nodecount--;
		return temp;
	}
	else return NULL;
	}

	// Return Record with key value k, NULL if none exist.
	// k: The key value to find. */
	// Return some record matching "k".
	// Return true if such exists, false otherwise. If
	// multiple records match "k", return an arbitrary one.
	E* find(const Key& k) const { return findhelp(root, k); }

	// Return the number of records in the dictionary.
	int size() { return nodecount; }

	void print() const { // Print the contents of the BST
	if (root == NULL) cout << "The BST is empty.\n";
	else printhelp(root, 0);
	}
  
};


// Visit -- prints out root
template <typename Key, typename E>
void BST<Key, E>::vist(BSTNode<Key,E>* r) const {
    cout << "Node - " << r->element() << endl;
}


// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearhelp(BSTNode<Key, E>* root) {
	if (root == NULL) return;
	if (root->returnLeftThread() == 1)
		clearhelp(NULL);
	else
	clearhelp(root->left());

	if (root->returnRightThread() == 1)
		clearhelp(NULL);
	else
	clearhelp(root->right());
	delete root;
}

// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::inserthelp(
	BSTNode<Key, E>* root, const Key& k, const E& it) {

	BSTNode<Key, E> *node = new BSTNode<Key, E>(k, it, NULL, NULL);

	if (root == NULL) { // Empty tree: create node
	return new BSTNode<Key, E>(k, it, NULL, NULL);
	}

	//Create two pointers: current and previous. Assign root to current and NULL to previous
	BSTNode<Key, E> *current = root, *previous = NULL;

	//Do this loop while current does not equal NULL
	while (current != NULL) 
	{
		previous = current;			//Assign current to previous

		//If the passed value is less than the previous value continue 
		if (k < previous->key())
		{
			//If there is a left thread then break
			if (current->returnLeftThread() == 1)
				break;
			else {		//Otherwise, assign the left of current to current
				current = current->left();
			}
		}
		else {			//If the value is not less then continue

			//If there is a right thread then break
			if (current->returnRightThread() == 1)
				break;
			else {		//Otherwise assign the value to the right of the current node to current
				current = current->right();
			}
		}
	}

	//Do this will the current node equals NULL
	if (current == NULL)
	{
		//If the new node value is less than the previous node's value
		if (k < previous->key())
		{
			previous->setLeft(node);		//Set the new node to be the left of the previous node
			node->setRight(previous);		//Make the new node thread to the previous node
			node->rightThread(1);			//Set the bit flag for right thread to 1
		}

		//If the new node value is not less that the previous node's value
		else 
		{
			previous->setRight(node);		//Set the new node to the right of the previous node
			node->setLeft(previous);		//Set the previous node to the left of the new node
			node->leftThread(1);			//Set the bit flag for the left thread of node to 1
		}
	}

	//If current is not NULL
	else 
	{
		//If the new node value is less than the previous node's value
		if (k < current->key()) {
			node->setLeft(current->left());	//Set the current node's left node to be the left node of
											//the newly created node
			node->leftThread(1);			//Set the bit flag of the left thread of node to 1
			node->setRight(current);		//Set the right node of the new node to the current node
			node->rightThread(1);			//Set the bit flag of the right thread of node to 1
			current->setLeft(node);			//Set the new created node to be the left node of current
			current->leftThread(0);			//Set the bit flag of current left thread to 0
		}

		//If the new node value is not less that the previous node's value
		else {
			node->setRight(current->right());	//Set the current node's right node to be the right node
												//of the newly created node
			node->rightThread(1);				//Set the bit flag of the right thread of node to 1
			node->setLeft(current);				//Set the left node of the new node to the current node
			node->leftThread(1);				//Set the bit flag of the left thread of node to 1
			current->setRight(node);			//Set the new created node to be the right node of current
			current->rightThread(0);			//Set the bit flag of current right thread to 0
		}
	}
	return node;
}


// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getmin(BSTNode<Key, E>* rt) {
	if (rt->left() == NULL)
		return rt;
	else return getmin(rt->left());
}


template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deletemin(BSTNode<Key, E>* rt) {
	if (rt->left() == NULL) // Found min
		return rt->right();
	else {                      // Continue left
		rt->setLeft(deletemin(rt->left()));
		return rt;
	}
}


// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
removehelp(BSTNode<Key, E>* rt, const Key& k) {
	if (rt == NULL) return NULL;    // k is not in tree
	else if (k < rt->key())
		rt->setLeft(removehelp(rt->left(), k));
	else if (k > rt->key())
		rt->setRight(removehelp(rt->right(), k));
	else {                            // Found: remove it
		BSTNode<Key, E>* temp = rt;
		if (rt->left() == NULL) {     // Only a right child
			rt = rt->right();         //  so point to right
			delete temp;
		}
		else if (rt->right() == NULL) { // Only a left child
			rt = rt->left();          //  so point to left
			delete temp;
		}
		else {                    // Both children are non-empty
			BSTNode<Key, E>* temp = getmin(rt->right());
			rt->setElement(temp->element());
			rt->setKey(temp->key());
			rt->setRight(deletemin(rt->right()));
			delete temp;
		}
	}
	return rt;
}


// Find a node with the given key value
template <typename Key, typename E>
E* BST<Key, E>::findhelp(BSTNode<Key, E>* root, const Key& k) const {
	if (root == NULL) return NULL;          // Empty tree
	if (k < root->key())
		return findhelp(root->left(), k);   // Check left
	else if (k > root->key())
		return findhelp(root->right(), k);  // Check right
	else {
		E* temp= new E;
		*temp = root->element();
		return temp;  // Found it
	}
}


// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::
printhelp(BSTNode<Key, E>* root, int level) const {
	if (root == NULL) return;           // Empty tree
	
	//Check to see if there is a thread. If there is a thread call printhelp, but
	//pass a NULL value
	if (root->returnLeftThread() == 1)
		printhelp(NULL, level);
	else
		printhelp(root->left(), level + 1);   // Do left subtree
  
	for (int i=0; i<level; i++)         // Indent to level
		cout << "  ";
  
	cout << root->key() << "\n";        // Print node value
	
	//Do the same as above, but this time check the right thread, not the left thread.
	if (root->returnRightThread() == 1)
		printhelp(NULL, level);
	else
		printhelp(root->right(), level + 1);  // Do right subtree

}


template <typename Key, typename E>
void BST<Key, E>::printInOrder() const {
	if (root == NULL)						//This is an empty tree 
	{
		cout << "\nThe Tree is Empty.";
		return;
	}

	//Make two pointers: current and previous. Current will hold the current node that the print
	//function is on. Previous will hold either it's parent or a node that is a thread.
	BSTNode<Key,E> *current, *previous;

	current = root;		//Assign the root to the current pointer

	//Do this loop while the current pointer is not NULL
	do {
		//Run this loop while current is not NULL
		while(current != NULL) {
			previous = current;			//Assign current to parent

			//If there is a left thread, break out of the loop
			if(current->returnLeftThread() == 1)
				break;
			else		//Otherwise continue to advance down the tree on the leftside
				current = current->left();			//Assign the next left value to current
		}

		cout << previous->element() << endl;		//Display the previous node because current is NULL
		current = previous->right();				//Assign the right value to current
		
		//This loop will run when current is not NULL and there is a right thread
		while((previous->returnRightThread() == 1) && (current != NULL)) {
			cout << current->element() << endl;		//Display the current node
			previous = current;						//Assign the current node to the previous pointer
			current = previous->right();			//Assign the next right value to current
		} 
	} while(current != NULL); 
}


template <typename Key, typename E>
void BST<Key, E>::printReverseOrder() const {
	if (root == NULL)			//The tree is empty 
	{
		cout << "\nThe Tree is Empty.";
		return;
	}

	//Make two pointers: current and previous
	BSTNode<Key,E> *current, *previous;

	current = root;			//Assign the root to current

	//Run this loop while current does not equal NULL
	do {
		//Run this loop while current does not equal NULL
		while(current != NULL) {
			previous = current;						//Assign current to previous
			
			//If there is a right thread then break out of the loop
			if(current->returnRightThread() == 1)
				break;
			else
				current = current->right();			//Assign the next right value to current
		}

		cout << previous->element() << endl;		//Display the previous node
		current = previous->left();					//Assign the previous left node to current
		
		//Loop that runs while there is a left thread and current does not equal NULL
		while((previous->returnLeftThread() == 1) && (current != NULL)) {
			cout << current->element() << endl;		//Display the current element
			previous = current;						//Assign the current node to previous
			current = previous->left();				//Assign the next left node to current
		} 
	} while(current != NULL); 
}

#endif