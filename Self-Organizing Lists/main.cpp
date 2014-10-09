#include <iostream>
#include "CountSelfOrderedList.h"
#include "MTFSelfOrderedList.h"
#include "TransposeSelfOrderedList.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
	CountSelfOrderedList<char> countCharList;
	//CountSelfOrderedList<string> countStringList;
	//MTFSelfOrderedList<string> mtfStringList;
	MTFSelfOrderedList<char> mtfCharList;
	TransposeSelfOrderedList<char> transposeCharList;
	//TransposeSelfOrderedList<string> transposeStringList;

	/*countCharList.add('A');
	countCharList.add('B');
	countCharList.add('C');
	countCharList.add('D');
	countCharList.add('E');
	countCharList.add('F');
	countCharList.add('G');
	countCharList.add('H');

	countCharList.find('F');
	countCharList.find('D');
	countCharList.find('F');
	countCharList.find('G');
	countCharList.find('E');
	countCharList.find('G');
	countCharList.find('F');
	countCharList.find('A');
	countCharList.find('D');
	countCharList.find('F');
	countCharList.find('G');
	countCharList.find('E');
	countCharList.find('H');
	countCharList.find('I');

	countCharList.printlist();

	mtfCharList.add('A');
	mtfCharList.add('B');
	mtfCharList.add('C');
	mtfCharList.add('D');
	mtfCharList.add('E');
	mtfCharList.add('F');
	mtfCharList.add('G');
	mtfCharList.add('H');

	mtfCharList.find('F');
	mtfCharList.find('D');
	mtfCharList.find('F');
	mtfCharList.find('G');
	mtfCharList.find('E');
	mtfCharList.find('G');
	mtfCharList.find('F');
	mtfCharList.find('A');
	mtfCharList.find('D');
	mtfCharList.find('F');
	mtfCharList.find('G');
	mtfCharList.find('E');
	mtfCharList.find('H');
	mtfCharList.find('I');
	
	mtfCharList.printlist();

	transposeCharList.add('A');
	transposeCharList.add('B');
	transposeCharList.add('C');
	transposeCharList.add('D');
	transposeCharList.add('E');
	transposeCharList.add('F');
	transposeCharList.add('G');
	transposeCharList.add('H');

	transposeCharList.find('F');
	transposeCharList.find('D');
	transposeCharList.find('F');
	transposeCharList.find('G');
	transposeCharList.find('E');
	transposeCharList.find('G');
	transposeCharList.find('F');
	transposeCharList.find('A');
	transposeCharList.find('D');
	transposeCharList.find('F');
	transposeCharList.find('G');
	transposeCharList.find('E');
	transposeCharList.find('H');
	transposeCharList.find('I');
	
	cout << endl;
	transposeCharList.printlist();*/


	countCharList.add('C');
	countCharList.add('D');
	countCharList.add('E');
	countCharList.add('G');
	countCharList.add('H');

	countCharList.find('D');
	countCharList.find('H');
	countCharList.find('H');
	countCharList.find('G');
	countCharList.find('H');
	countCharList.find('E');
	countCharList.find('G');
	countCharList.find('H');
	countCharList.find('G');
	countCharList.find('H');
	countCharList.find('E');
	countCharList.find('C');
	countCharList.find('E');
	countCharList.find('H');
	countCharList.find('G');

	countCharList.printlist();

	mtfCharList.add('C');
	mtfCharList.add('D');
	mtfCharList.add('E');
	mtfCharList.add('G');
	mtfCharList.add('H');

	mtfCharList.find('D');
	mtfCharList.find('H');
	mtfCharList.find('H');
	mtfCharList.find('G');
	mtfCharList.find('H');
	mtfCharList.find('E');
	mtfCharList.find('G');
	mtfCharList.find('H');
	mtfCharList.find('G');
	mtfCharList.find('H');
	mtfCharList.find('E');
	mtfCharList.find('C');
	mtfCharList.find('E');
	mtfCharList.find('H');
	mtfCharList.find('G');
	
	mtfCharList.printlist();

	transposeCharList.add('C');
	transposeCharList.add('D');
	transposeCharList.add('E');
	transposeCharList.add('G');
	transposeCharList.add('H');

	transposeCharList.find('D');
	transposeCharList.find('H');
	transposeCharList.find('H');
	transposeCharList.find('G');
	transposeCharList.find('H');
	transposeCharList.find('E');
	transposeCharList.find('G');
	transposeCharList.find('H');
	transposeCharList.find('G');
	transposeCharList.find('H');
	transposeCharList.find('E');
	transposeCharList.find('C');
	transposeCharList.find('E');
	transposeCharList.find('H');
	transposeCharList.find('G');
	
	cout << endl;
	transposeCharList.printlist();

	/*ifstream inFile;
	inFile.open("test.txt");

	while (inFile)
	{
		string word;
		inFile >> word;
		countStringList.find(word);
		mtfStringList.find(word);
		transposeStringList.find(word);
	}

	countStringList.printlist(10);
	mtfStringList.printlist(10);
	transposeStringList.printlist(10);*/

	cout << endl << endl;
	system("pause");
	return 0;
}