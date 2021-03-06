#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[]) {
	// Must include one input file
	if (argc != 2)
	{
		cerr << "Incorrect number of command line arguments" << endl;
		return 1;
	}
	
	// Create file stream and array of words
	ifstream inFile(argv[1]);
	int numWords;
	inFile >> numWords;
	string* wordList= new string[numWords];

	for (int i=1; i<=numWords; i++)
	{
		// store words backwards
		inFile >> wordList[numWords-i];
	}

	// print contents of wordList
	for (int i=0; i<numWords; i++)
	{
		cout << wordList[i];
		cout << endl;
	}

	delete[] wordList;
	return 0;
}