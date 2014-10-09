#include "BST.h"
#include <string>

using namespace std;

int main() 
{
	BST<int, string> tree1;
	cout << "Testing my modified inserthelp function.";
	tree1.insert(77, "seventy-seven");
	tree1.insert(70, "seventy");
	tree1.insert(75, "seventy-five");
	tree1.insert(66, "sixty-six");
	tree1.insert(79, "seventy-nine");
	tree1.insert(68, "sixty-eight");
	tree1.insert(67, "sixty-seven");
	tree1.insert(69, "sixty-nine");
	tree1.insert(90, "ninety");
	tree1.insert(85, "eighty-five");
	tree1.insert(83, "eighty-three");
	tree1.insert(87, "eighty-seven");
	tree1.insert(65, "sixty-five");

	cout << "\nMy BST tree size is " << tree1.size();

	cout << "\nMy tree's structure is (tests my changes to the printhelp function):\n";
	tree1.print();

	cout << "\nInorder printing of my tree\n(tests my right threads and printInorder function):\n";
	tree1.printInOrder();
	
	cout << "\nReverse order printing of my tree\n(tests my left threads and printReverse function):\n";
	tree1.printReverseOrder();

	char exitChar;
	cout << "\nPress any key and <enter> to exit: ";
	cin >> exitChar;
	return 0;
}