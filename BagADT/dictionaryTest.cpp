#include <iostream>
#include <string>
#include "BDictionary.h"
#include "kvpair.h"

using namespace std;


int main() {

	cout << "Dictionary and Bag Driver Program\n";

	BDict<int, int> myIntIntDict;					//Dictionary with Int, Int
	BDict<int, string> myIntStringDict;				//Dictionary with Int, String
	BDict<string, string> myStringStringDict;		//Dictionary with String, String
	BDict<string, int> myStringIntDict;				//Dictionary with String, Int

	int num1 = 5;									//Integer used for passing to functions
	string testString = "String5";					//String used for passing to functions

	/*myIntIntDict *****************************************************************************************/

	cout << "\nTesting dictionary with <int, int> KV Pair" << endl;
	
	//Insert 8 values into the Int, Int dictionary
	cout << "\nINSERT: ";
	myIntIntDict.insert(1, 2);
	myIntIntDict.insert(3, 4);
	myIntIntDict.insert(5, 6);
	myIntIntDict.insert(7, 8);
	myIntIntDict.insert(9, 21);
	myIntIntDict.insert(10, 22);
	myIntIntDict.insert(11, 23);
	myIntIntDict.insert(12, 24);
	myIntIntDict.insert(13, 25);
	myIntIntDict.insert(14, 26);

	//Output the size of the dictionary and then call the removeAny function and pass it a value
	cout << "Size of myIntIntDict is " << myIntIntDict.size();
	cout << "\nREMOVE ANY: My int data is ";
	myIntIntDict.removeAny(num1);

	//Output the size of the dictionary and pass a key and value to the find function in dictionary
	cout << "\nSize of myIntIntDict is " << myIntIntDict.size();
	cout << "\nFIND: ";
	myIntIntDict.find(10, num1);
	
	//Output the size of the dictionary and call the remove function based upon a given KVpair.
	cout << "\nSize of myIntIntDict is " << myIntIntDict.size();
	cout << "\nREMOVE: ";
	myIntIntDict.remove(9, num1);

	//Output the size of the dictionary, run the clear function, and output the size again.
	cout << "\nSize of myIntIntDict is " << myIntIntDict.size();
	myIntIntDict.clear();
	cout << "\nCLEAR: Size of myIntIntDict is " << myIntIntDict.size();
	
	/*myIntStringDict *****************************************************************************************/

	cout << "\n\n\nTesting dictionary with <int, string> KV Pair" << endl;
	
	//Insert 4 values into the Int, String dictionary
	cout << "\nINSERT: ";
	myIntStringDict.insert(1, "String1");
	myIntStringDict.insert(2, "String2");
	myIntStringDict.insert(3, "String3");
	myIntStringDict.insert(4, "String4");
	
	//Output the size of the dictionary and then call the removeAny function
	cout << " Size of myIntStringDict is " << myIntStringDict.size();
	cout << "\nREMOVE ANY: My string data is ";
	myIntStringDict.removeAny(testString);

	//Output the size of the dictionary and pass a key and value to the find function in dictionary
	cout << "\nSize of myIntStringDict is " << myIntStringDict.size();
	cout << "\nFIND: ";
	myIntStringDict.find(1, testString);
	
	//Output the size of the dictionary and call the remove function based upon a given KVpair.
	cout << "\nSize of myIntStringDict is " << myIntStringDict.size();
	cout << "\nREMOVE: ";
	myIntStringDict.remove(2, testString);

	//Output the size of the dictionary, run the clear function, and output the size again.
	cout << "\nSize of myIntStringDict is " << myIntStringDict.size();
	myIntStringDict.clear();
	cout << "\nCLEAR: Size of myIntStringDict is " << myIntStringDict.size();

	/*myStringStringDict *****************************************************************************************/

	cout << "\n\n\nTesting dictionary with <string, string> KV Pair" << endl;
	
	//Insert 4 values into the String, String dictionary
	cout << "\nINSERT: ";
	myStringStringDict.insert("String1", "String5");
	myStringStringDict.insert("String2", "String6");
	myStringStringDict.insert("String3", "String7");
	myStringStringDict.insert("String4", "String8");
	
	//Output the size of the dictionary and then call the removeAny function
	cout << " Size of myStringStringDict is " << myStringStringDict.size();
	cout << "\nREMOVE ANY: My string data is ";
	myStringStringDict.removeAny(testString);

	//Output the size of the dictionary and pass a key and value to the find function in dictionary
	cout << "\nSize of myStringStringDict is " << myStringStringDict.size();
	cout << "\nFIND: ";
	myStringStringDict.find("String4", testString);		//This will test when find fails
	
	//Output the size of the dictionary and call the remove function based upon a given KVpair.
	cout << "\nSize of myStringStringDict is " << myStringStringDict.size();
	cout << "\nREMOVE: ";
	myStringStringDict.remove("String3", testString);

	//Output the size of the dictionary, run the clear function, and output the size again.
	cout << "\nSize of myStringStringDict is " << myStringStringDict.size();
	myStringStringDict.clear();
	cout << "\nCLEAR: Size of myStringStringDict is " << myStringStringDict.size();

	/*myStringIntDict *****************************************************************************************/

	cout << "\n\n\nTesting dictionary with <string, int> KV Pair" << endl;
	
	//Insert 4 values into the String, Int dictionary
	cout << "\nINSERT: ";
	myStringIntDict.insert("String1", 5);
	myStringIntDict.insert("String2", 6);
	myStringIntDict.insert("String3", 7);
	myStringIntDict.insert("String4", 8);
	
	//Output the size of the dictionary and then call the removeAny function
	cout << " Size of myStringIntDict is " << myStringIntDict.size();
	cout << "\nREMOVE ANY: My string data is ";
	myStringIntDict.removeAny(num1);

	//Output the size of the dictionary and pass a key and value to the find function in dictionary
	cout << "\nSize of myStringIntDict is " << myStringIntDict.size();
	cout << "\nFIND: ";
	myStringIntDict.find("String3", num1);
	
	//Output the size of the dictionary and call the remove function based upon a given KVpair.
	cout << "\nSize of myStringIntDict is " << myStringIntDict.size();
	cout << "\nREMOVE: ";
	myStringIntDict.remove("String3", num1);

	//Output the size of the dictionary, run the clear function, and output the size again.
	cout << "\nSize of myStringIntDict is " << myStringIntDict.size();
	myStringIntDict.clear();
	cout << "\nCLEAR: Size of myStringIntDict is " << myStringIntDict.size();

	/*Bag Functions *****************************************************************************************/
	//These are functions to test the other bag functions that have no directly correlating dictionary function.

	cout << endl << endl;
	myStringIntDict.insert("TestString1", 1);		//Insert 2 values into the String, Int dictionary
	myStringIntDict.insert("TestString2", 2);
	myStringIntDict.inspectTop();					//Function to redirect and call the Bag's inspectTop function
	myStringIntDict.print();						//Function to redirect and call the Bag's print function
	myStringIntDict.emptyDictionary();				//Function to redirect and call the Bag's emptyBag function
	myStringIntDict.bagCapacity();

	//Print the size of the dictionary to prove that emptyDictionary worked.
	cout << "\nSize of myStringIntDict is " << myStringIntDict.size();

	//This will add an object to the bag using the assignment operator
	cout << "\n\nTest of the addition assignment operator";
	myIntIntDict.opTest(1,1);
	myIntIntDict.print();
	
	
	//Allow user to exit
	char exitChar;
	cout << "\n\nPlease enter any key and press <enter> to exit:";
	cin >> exitChar;
	return 0;
}