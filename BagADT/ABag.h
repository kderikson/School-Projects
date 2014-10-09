#include <string>
#include "bagADT.h"
#include "kvpair.h"

#ifndef ABAG_H
#define ABAG_H

const int MAX_SIZE = 10;					//Global constant for max size of Bag array
const int ZERO = 0;							//Global constant for the number zero
const int ONE = 1;							//Global constant for the number one

template <typename F>						//Template with typename F
class ABag : public Bag<F> {				//Class ABag derived from the Bag ADT
public:

	ABag() {							    //ABag Constructor
		BagArray = new F[MAX_SIZE];			//Make BagArray of type F with max size elements
		capacity = MAX_SIZE;				//Set the capacity to max size
		used = ZERO;						//Set the number of used elements to zero
	}

	~ABag() {								//ABag destructor
		delete [] BagArray;					//Delete the memory of Bag array
		BagArray = NULL;					//Set the pointer to NULL
	}

	bool addItem(const F& something) {		//Function to add item to Bag array
		if (used >= capacity)				//If there is no room in the array return false
			return false;
		
		BagArray[used] = something;			//Add given KVpair to the array at the top slot

		used++;								//Increment used
		return true;
	}

	void clear() {							//Function to clear and reintialize the Bag array
		delete [] BagArray;					//Delete the memory of BagArray
		BagArray = new F[MAX_SIZE];			//Declare new array based on max size
		used = ZERO;						//Set used to zero
	}

	bool remove(const F& something) {		//Function to remove a given element from the Bag
		if (used == ZERO)					//If there is nothing in the bag return false
			return false;
		
		int index = ZERO;					//Set index to zero
		F temp;								//Declare temporary variable of type F
		temp = something;					//Assign KVpair argument to temporary

		//Increment index until the Bag's key matches the argument's key
		while (BagArray[index].key() != temp.key())
		{
			index++;
		}

		//Does not allow a key to be zero
		if (index == used) {
			cout << "\nKeys are not allowed to be zero.";
			return false;
		}

		//Display which key was removed and it's corresponding value
		cout << "Removed key " << BagArray[index].key() << " which was " << BagArray[index].value();

		//Shift everything in the Bag array down
		for (; index < used ; index++)
		{
			BagArray[index] = BagArray[index + 1];

		}

		used--;									//Decrement used

		return true;
	}

	bool removeTop(F& something) {				//Function to remove the top value from BagArray
		
		int top = used - ONE;					//Make an index for the last object in BagArray
		
		F temp = BagArray[top];					//Assign the top value to a temporary value
		
		something = temp;						//Update the given argument to the correct top value
		
		BagArray[top] = BagArray[top + ONE];	//Shift the array down
		
		used--;									//Decrement used
		return true;
	}
	
	bool find(F& something) const {				//Function to find a value based upon given KVpair

		//Loops through until key is matched or index = used
		for (int index = ZERO; index < used; index++)
		{
			//If the key is matched update the argument given to find
			if (BagArray[index].key() == something.key())
			{
				
				F temp;						//Create temp value
				temp = BagArray[index];		//Take value at correct index in array and assign to temp
				something = temp;			//Update argument with temp variable
				return true;
			}
		}
		return false;
	}

	const F& inspectTop() const {			//Function to examine the last value in the array
		
		int top = used - ONE;				//Make a top variable

		//Assign correct KVpair to temp variable and cout the key and value
		F temp = BagArray[top];
		cout << "\nTop key: " << temp.key();
		cout << "\nTop value: " << temp.value();
		return temp;
	}

	void emptyBag() {						//Function to empty the entire bag

		//Loop to overwrite all the values in the bag 
		for (int index = ZERO; index < used ; index++)
		{
			BagArray[index] = BagArray[index + ONE];
		}
		used = ZERO;						//Set used equal to zero
	}

	void operator+=(const F& addend)		//Operator overload for addition assignment
	{	
		addItem(addend);					//Call the addItem function and pass addend
		return;								
	}

	int size() const {						//Function to show the size of the Bag
		return used;						//Return used variable
	}

	int bagCapacity() const {				//Function to show the capacity of the Bag
		return capacity;
	}

	void print() {							//Function to print all information in the Bag

		//Loop through the Bag and print all key's and corresponding values
		for (int i = ZERO; i < used; i++)
		{
			cout << "\nKey: " << BagArray[i].key() 
		    << "\tValue: " << BagArray[i].value();
		}
	}
private:
	F *BagArray;							//Pointer of type F to BagArray
	int used;								//Integer to signify how many slots are used
	int capacity;							//Integer to show the capacity of the Bag
};



#endif