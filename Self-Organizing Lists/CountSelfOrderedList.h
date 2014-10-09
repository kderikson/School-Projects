#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

#ifndef COUNTSELFORDEREDLIST_H
#define COUNTSELFORDEREDLIST_H

template <typename E>
class CountSelfOrderedList : public SelfOrderedListADT<E> {
public:

	//Count list constructor, set compares to zero
	CountSelfOrderedList() {numOfCompares = 0;}

	~CountSelfOrderedList() {}

	//Function for finding a user given value
	bool find(const E& it) {

		//Variable for triggering parts of code
		int found = 0;

		//Move the list to the start
		list.moveToStart();

		//Loop through the list checking for duplicate values
		for (int i = 0; i < list.length(); i++)
		{
			//Increment the number of compares
			numOfCompares++;

			//If there is a duplicate found break out of the loop
			if (list.getValue() == it)
			{
				
				found = 1;		//set found to 1
				break;
			}
			
			//Advance down the list
			list.next();
			
		}

		//Increments the number of times accessed if a duplicate value is found
		if (found == 1)
		{
			//Grab current amount of accesses
			int temp = list.getTimesAccessed();

			//Set the new number of accesses
			list.setTimesAccessed(temp + 1);

			//Call the reorder function
			reorder();
			return true;
		}

		//If no duplicate value is found then insert the value at the end of the list
		else
		{
			list.moveToEnd();						//Move list to the end
			list.insert(it);						//Insert the value
			list.setTimesAccessed(0);				//Set the number of accesses at zero
			return true;
		}

		return false;
	}

	//Function to add a value to the end of the list
	void add(const E& it) {
		list.append(it);			//Call list append function
	}

	//Function to print the list
	void printlist() const {
		cout << "Count Heuristic: " << "\tSize of List: " << size();		//Print the size of the list
		cout << "\nNumber of Compares: " << getCompares();					//Print the number of compares
		list.print();		//Print the list values
		cout << endl;
		
	}

	//Same as above, but will only print a given number of values
	void printlist(int n) const {
		cout << "\n\nCount Heuristic: " << "\tSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print(n);			//Call function to print specific number of values
	}

	//Function to return the number of compares
	int getCompares() const {
		return numOfCompares;
	}

	int size() const {
		return list.length();
	}

	//Function to reorder the items based on their number of accesses
	void reorder() {

		//Grab the number of accesses for the item you wish to swap
		int toSwap = list.getTimesAccessed();

		//Go backwards in the list
		list.prev();

		//Grab the number of accesses for the previous neighbor
		int prev = list.getTimesAccessed();

		//Loop to swap elements until the number of accesses of the current item is less than the previous element
		while (toSwap > prev)
		{
			list.next();

			//Remove the item
			E temp = list.remove();

			//Set the number of accesses for the item that was shifted down
			list.setTimesAccessed(prev);
			list.prev();

			//Insert the removed item
			list.insert(temp);

			//Set the correct number of accesses for the newly inserted item
			list.setTimesAccessed(toSwap);

			//Go forward and set the correct number of accesses
			list.next();
			list.setTimesAccessed(prev);

			//Go back two in the list and grab the number of accesses
			list.prev();
			list.prev();
			prev = list.getTimesAccessed();
		}
		
	}

private:
	CountSelfOrderedList(const CountSelfOrderedList&) {}
	//CountSelfOrderedList operator=(const CountSelfOrderedList&) {}
	LList<E> list;
	int numOfCompares;
};

#endif