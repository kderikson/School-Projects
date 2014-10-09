#include "dictionaryADT.h"
#include "kvpair.h"
#include "ABag.h"

#ifndef BDICT_H
#define BDICT_H

const int MAX_CAP = 10;											//Global constant for max capacity

template <typename Key, typename E>								//Template with typenames Key, E
class BDict : public Dictionary<Key, E> {						//Class BDict derived from Dictionary
public:
	BDict(int size = MAX_CAP) {									//Constructor that intializes size to MAX_CAP
		bag = new ABag<KVpair<Key, E> >;						//Create a new bag
	}

	~BDict()													//Destructor
	{
		delete [] bag;											//Delete the bag array and assign the pointer to NULL
		bag = NULL;
	}

	void clear() {												//Clear function. Calls Bag's clear function.
		bag->clear();
	}

	void insert(const Key& k, const E& e) {						//Insert function takes two arguments: A key and a value
		bool success = NULL;									//Create bool called success and assign it NULL

		KVpair<Key, E> temp(k, e);								//Create a temporary KVpair
		tempKey = k;											//Assign k to the tempKey
		success = bag->addItem(temp);							//Call the addItem function and assign return to success varaible

		//If the return is false cout error message
		if (success == false) {
			cout << "\nYou may not add any more values.\n";
		}
	}

	bool remove(const Key& k, E& rtnVal) {						//Remove function takes a const Key and a value
		KVpair<Key, E> temp(k, rtnVal);							//Create a temp KVpair
		bag->remove(temp);										//Pass the temp KVpair to the Bag remove function
		return true;
	}

	bool removeAny(E& returnValue) {							//Function to remove any KVpair
		Key k = tempKey;										//Create a temporary key
		KVpair<Key, E> temp(k, returnValue);					//Create a temporary KVpair
		bool answer = bag->removeTop(temp);						//Call the Bag's removeTop function and assign the return to answer
		
		//If the return is true cout the value that was removed
		if (answer == true)
		{
			cout << temp.value();
		}
		
		return false;
	}

	bool find(const Key& k, E& returnValue) const {				//Function to find a value based upon a key and value
		KVpair<Key, E> temp(k, returnValue);					//Create a temporary KVpair from give key and value
		bool answer = bag->find(temp);							//Call the Bag's find function and assign the return to answer
		
		//If the return is true cout the key and value that was found
		if (answer == true)
		{
			cout << "My data at key == " << temp.key() << " is: " << temp.value();
			return true;
		}
		
		//If no value was found cout error
		cout << "No result was found.";
		return false;
	}

	int size()													//Function to give the size of the dictionary
	{
		return bag->size();										//Call Bag's size function
	}

	bool inspectTop()											//Function to call Bag's inspectTop function
	{
		//If the size is zero then there are no objects
		if (size() == ZERO)
		{
			cout << "\nThere are no objects in the dictionary.";
			return false;
		}

		bag->inspectTop();										//Call Bag's inspectTop function
		return true;
	}

	void print()												//Call Bag's print function
	{
		bag->print();
	}

	void emptyDictionary()										//Call the empty Bag function
	{
		bag->emptyBag();
	}

	void bagCapacity()											//Call the Bag capacity function
	{
		cout << "\nBag Capacity: " << bag->bagCapacity();
	}
	void opTest(const Key& k, const E& e) {						//Add KVpair to the bag using the assignment
		KVpair<Key, E> tempKVpair(k,e);							//operator
		(*bag) += tempKVpair;
	}
private:
	ABag<KVpair<Key, E> >* bag;									//Make a pointer called Bag
	Key tempKey;												//Create a temporary key variable
};

#endif