/* 
 * File:   bagADT.hpp -- Bag ADT for CSCI 215 Assignment
 * Author: Dad's ASUS
 *
 * Created on July 14, 2012, 11:46 AM
 */

#ifndef BAGADT_HPP
#define	BAGADT_HPP

#include <stdlib.h>
//#include "book.h"

template <typename E>
class Bag {
public:
    Bag() {}            // base constructor
    virtual ~Bag() {}   // base destructor
    
    // Insert a new item into the bag -- return false if fails and true if
    // successful
    virtual bool addItem(const E& item) = 0;
    
    // Remove an items from the bag -- return false if fails
	virtual bool remove(const E& item) = 0;
    
    // Removes the top record from the bag, puts it in returnValue, and
    // returns true if the bag is not empty.  If the bag is empty the 
    // function returns false.
	virtual bool removeTop(E& returnValue) = 0; 
    
    // finds the record using returnValue and if the record is found updates
    // the record based on the contents of the bag and returns true.  If the
    // record is not found the function returns false;
	virtual bool find(E& returnValue) const = 0;
    
    // inspect the top of the bag
	virtual const E& inspectTop() const = 0;
    
    // empties the bag
	virtual void emptyBag() = 0;

    // use the += operator to add an item to the bag
	virtual void operator+=(const E& addend) = 0;
    
    // get the size of the bag
	virtual int size() const = 0;
    
    // get the capacity of the bag
	virtual int bagCapacity() const = 0;

	//print function
	virtual void print() = 0;


private:
    Bag(const Bag&) {}    // protect the copy constructor
    void operator=(const E&) {} // protect assignment
    
};

#endif	/* BAGADT_HPP */

