#include "BufferBlock.h"
#include "ABufferPool.h"
#include <iostream>

using namespace std;

int main()
{
	ABufferPool somePool;

	char* churchill = new char [4097];

	//Ask to get a variety of blocks from a variety of places
	somePool.getbytes(churchill, 10, 1);				//Pos = 1
	somePool.getbytes(churchill, 1000, 10000);			//Pos = 3
	somePool.getbytes(churchill, 50, 25000);			//Pos = 7
	somePool.getbytes(churchill, 100, 500);				//Pos = 1
	somePool.getbytes(churchill, 500, 18000);			//Pos = 5
	somePool.getbytes(churchill, 600, 23000);			//Pos = 6
	somePool.getbytes(churchill, 200, 9000);			//Pos = 3

	//Order should be 3, 6, 5, 1, 7

	char exitChar;
	cout << "\nEnter any character and press <enter> to exit: ";
	cin >> exitChar;
	return 0;
}

