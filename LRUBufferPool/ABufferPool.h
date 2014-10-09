#include "BufferPoolADT.h"
#include "BufferBlock.h"
#include <math.h>

#ifndef ABUFFERPOOL_H
#define ABUFFERPOOL_H

class ABufferPool : public BufferPool {
public:
	//Buffer pool constructor
	ABufferPool() {
		numOfBlocks = 0;			//Variable to hold the number of blocks
	}

	//Buffer pool destructor
	~ABufferPool() {
		delete [] pool;				//Deletes the pool dynamic array upon program exit
									//See approach doc for information regarding this
	}

	//Dummy insert function
	void insert(char* space, int sz, int pos) {}

	//Function to grab the specified bytes
	void getbytes(char* space, int sz, int pos) {
		
		//Assign the pos parameter to a float variable
		position = static_cast<float>(pos);
		
		//If the number of blocks is 0
		if (numOfBlocks == 0)
		{
			//Create  a new buffer block object
			BufferBlock *temp = new BufferBlock(pos, sz);
			
			//Assign the object to a slot in the pool array
			pool[numOfBlocks] = temp;
			
			//Get the 4096 bytes of data
			space = pool[numOfBlocks]->getData();
			
			//Increment the number of blocks
			numOfBlocks++;
		}
		//If the number of blocks is five
		else if (numOfBlocks == 5)
		{
			//Set forward flag to true
			forward = true;

			//Loop through pool array looking for the same block of information
			for (int i = 0; i < numOfBlocks; i++)
			{
				//If the same block of bytes is found then move to top of the pool array
				if (pool[i]->getBlockId() == calcPos())
				{
					BufferBlock* temp;		//Temp bufferblock object

					temp = pool[i];			//Grab the same byte block

					//Shift all elements in array down
					for (int j = i; j > 0; j--)
					{
						pool[j] = pool[j - 1];
					}

					pool[0] = temp;			//Assign the byte block to the top of the array
					forward = false;		//Set the forward flag to false
				}
			}

			//Do this if the requested byte block is not in the array
			if (forward)
			{
				//Create a new buffer block
				BufferBlock* newBlock = new BufferBlock(pos, sz);

				//Shift all elements in the array down
				for (int j = numOfBlocks; j > 0; j--)
				{
					pool[j] = pool[j - 1];
				}

				pool[0] = newBlock;			//Assign the new block to the top of the array
				numOfBlocks = 5;			//Keep the number of blocks at five
				space = pool[numOfBlocks]->getData();		//Grab the bytes of data and assign them to the psace array
			}

		}
		//If the number of blocks is greater than zero and not five
		else {
			//Loop through the pool array and see if there is a similar byte block
			for (int i = 0; i < numOfBlocks; i++)
			{
				//If a similar byte block is found
				if (pool[i]->getBlockId() == calcPos())
				{
					BufferBlock* temp;		//Create temp buffer block object

					temp = pool[i];			//Assign the similar block to the temp object

					//Shift all elements in the array down
					for (int j = i; j > 0; j--)
					{
						pool[j] = pool[j - 1];
					}

					pool[0] = temp;			//Assign the block to the top of the array

					creationFlag = false;	//Assign the creation flag to false
				}
				//If no similar block is found
				else
					creationFlag = true;	//Assign the creation flag to true
			}

			//If there are no similar blocks found in the array
			if (creationFlag)
			{
				//Create a new Buffer Block
				BufferBlock* newBlock = new BufferBlock(pos, sz);

				//Shift all elements in the array down
				for (int j = numOfBlocks; j > 0; j--)
				{
					pool[j] = pool[j - 1];
				}

				pool[0] = newBlock;				//Assign the new block to the top of the array
				space = pool[0]->getData();		//Grab the byte data and put it in the space array
				numOfBlocks++;					//Increment the number of blocks
			}
		}
		printBufferBlockOrder();				//Call the print buffer block function
	}

	//Function to calculate the position of the block
	int calcPos() {
		int temp = 0;		//Make temp variable
		//Divide the byte position by 4096 and use the ceil function to round up
		temp = ceil(position / static_cast<float>(4096));
		return temp;		//Return the temp variable
	}

	//Function to print the buffer blocks in order
	void printBufferBlockOrder() {
		cout << "\nI am reading (getData()) the following from block " << getLRUBlockID() << ":\n";
		
		pool[0]->textDisplay();		//Function to display the given block of text
		
		cout << "\n\nAfter the request my buffer block order from most recently used to LRU is:\n";
		
		//Display all the block Id's from MRU to LRU
		for (int i = 0; i < numOfBlocks; i++)
		{
			cout << pool[i]->getBlockId() << ",  ";
		}
		
		cout << endl << endl;
	}

	//Get the block ID
	int getLRUBlockID() {
		int temp = 0;
		temp = pool[0]->getBlockId();
		return temp;
	}
private:
	int numOfBlocks;				//Holds the number of blocks
	bool creationFlag, forward;		//Flags to stop or start forward progress
	float position;					//Holds the block position
	BufferBlock* pool[5];			//Array of buffer blocks
};

#endif