#include <fstream>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

#ifndef BUFFERBLOCK_H
#define BUFFERBLOCK_H

class BufferBlock {
public:
	//BufferBlock constructor
	BufferBlock(int blockId, int writeSize = 0, int arraySize = 4096) {
		//Create a dynamic character array of size 4097
		charArray = new char[arraySize + 1];
		
		//Set position equal to blockId parameter
		position = blockId;

		//Call function to calculate the block id
		calcBlockId();
		
		//Set size to arraySize parameter
		size = arraySize;
		
		//Set sizeToDisplay to writeSize parameter
		sizeToDisplay = writeSize;
	}

	~BufferBlock() { delete [] charArray; }

	//Function to get the data
	char* getData() {

		//Create a file stream
		ifstream fin;

		//Open the test file
		fin.open("churchill.txt");
	
		//If the test file is working
		if (fin)
		{
			//Get the correct positioning
			fin.seekg(position - 1, fin.beg);

			//Grab the number of characters specified by size and write them to charArray
			fin.get(charArray, size);

			//Add the null character to the end
			charArray[size] = '\0';
		}

		//If the file fails display error message
		else
			cout << "\nNo file detected.";

		fin.close();		//Close the file

		return charArray;	//Return the charArray
	}

	//Function to return the blockId
	int getBlockId() {
		return id;
	}

	//Function to calculate the blockId
	void calcBlockId()
	{
		//Divide the position by 4096 and round up
		id = ceil(position / static_cast<float>(4096));
	}

	//Function to display the text of a certain length
	void textDisplay() {
		cout.write(charArray, sizeToDisplay);
	}

private:
	int id,					//Holds the block ID
		size,				//Holds the size to be gathered
		position,			//Holds the starting position
		sizeToDisplay;		//Holds the size of information to display
	char* charArray;		//Pointer to array of characters
};

#endif