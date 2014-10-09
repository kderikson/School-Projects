#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

#ifndef TRANSPOSESELFORDEREDLIST_H
#define TRANSPOSESELFORDEREDLIST_H

template <typename E>
class TransposeSelfOrderedList : public SelfOrderedListADT<E> {
public:

	//Transpose constructor, set the number of comapres to zero
	TransposeSelfOrderedList() {numOfCompares = 0;}

	~TransposeSelfOrderedList() {}

	//Function to find a specified element in the list
	bool find(const E& it) {

		//Variable to determine whether to continue in the code or not
		int found = 0;

		//Move the list to the start
		list.moveToStart();


		//Loop to determine whether there are duplicates in the list
		for (int i = 0; i < list.length(); i++)
		{
			//Increment the number of compares
			numOfCompares++;

			//If there is a duplicate found, set the found flag to one and break out of the loop
			if (list.getValue() == it)
			{
				
				found = 1;
				break;
			}

			//Advance the list
			list.next();
			
		}

		//If there is a duplicate increment the number of times accessed for that element and call the reorder function
		if (found == 1)
		{
			//Get the current number of item accesses
			int temp = list.getTimesAccessed();
			
			//Set the new number of item accesses
			list.setTimesAccessed(temp + 1);

			//Call the reorder function
			reorder();
			return true;
		}

		//Otherwise, add the element to the end of the list and set the number of accesses to zero
		else
		{
			list.moveToEnd();
			list.insert(it);
			list.setTimesAccessed(0);
			return true;
		}

		return false;
	}

	//Function to call the list append function
	void add(const E& it) {
		list.append(it);
	}

	//Function to print the list
	void printlist() const {
		cout << "\nTranspose Heuristic: " << "\tSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print();		//Call the list print function
		
	}

	//Function to reorder the elements by swapping them with the element previous
	void reorder() {

		//Grab the first value in the list
		E frontVal = list.frontValue();

		//Grab the last value in the list
		E endValue = list.tailValue();


		//If the current value matches the front value then stop the function
		if (list.getValue() == frontVal)
		{
			return;
		}

		//If the current value matches the value at the end of the list
		if (list.getValue() == endValue)
		{
			//Grab the access number for the end of the list
			int endValue = list.getTimesAccessed();
			
			//Go back one in the list
			list.prev();
			
			//Grab the access number for the previous element
			int prevValue = list.getTimesAccessed();

			//Remove the previous element
			E temp = list.remove();

			//Set the correct access value
			list.setTimesAccessed(prevValue);

			//Move the list to the end
			list.moveToEnd();

			//Insert the removed value
			list.insert(temp);

			//Set the correct number of accesses
			list.setTimesAccessed(prevValue);

			//Go back one in the list
			list.prev();

			//Set the correct number of accesses
			list.setTimesAccessed(endValue);
			return;
		}

		//Grab the number accesses of the item to be swapped
		int toSwap = list.getTimesAccessed();

		//Step back one in the list
		list.prev();

		//Get the number of accesses for the previous item
		int prev = list.getTimesAccessed();

		//Go back to the element to be swapped
		list.next();

		//Grab the number of accesses for that value
		int curr = list.getTimesAccessed();

		//Advance down the list
		list.next();
		
		//Grab the number of accesses for the element after the one to be swapped
		int next = list.getTimesAccessed();
		
		//Go back to the element to be removed
		list.prev();

		//Remove the element
		E temp = list.remove();

		//Set the correct number of accesses for the next value
		list.setTimesAccessed(next);

		//Go backwards in the list
		list.prev();

		//Grab the number of accesses
		prev = list.getTimesAccessed();

		//Insert the removed value
		list.insert(temp);

		//Set the correct number of accesses for removed value
		list.setTimesAccessed(toSwap);

		//Advance down the list and set the correct number of accesses
		list.next();
		list.setTimesAccessed(prev);

	}

	//Function to print a specified number of items from the list
	void printlist(int n) const {
		cout << "\n\nTranspose Heuristic: " << "\tSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print(n);			//Call the list print function giving it a specific number of items to print
	}

	//Function to return the number of compares
	int getCompares() const {
		return numOfCompares;
	}

	//Function to return the size of the list
	int size() const {
		return list.length();
	}

private:
	TransposeSelfOrderedList(const TransposeSelfOrderedList&) {}
	//TransposeSelfOrderedList operator=(const TransposeSelfOrderedList&) {}
	LList<E> list;
	int numOfCompares;

};

#endif