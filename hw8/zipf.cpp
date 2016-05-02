#include "Map.h"
#include "hash.h"
#include "splTree.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char * argv[]) {
    clock_t start;
    double duration;

    start = clock();

    /* Your algorithm here */
    ifstream inFile(argv[2]);
    Map* wordBank;
    string currWord;
    int algorithm = atoi(argv[1]);

    if (algorithm == 4)
    {
    	wordBank = new SplayTree<string,int>();
    }
    else if (algorithm == 5)
    {
    	wordBank = new Hash();
    }
    else
    {
    	cerr << "Choose (4) for Hash Table or (5) for Splay Tree" << endl;
    	return 1;
    }
    while (!inFile.eof())
	{
		inFile >> currWord;
		wordBank->add(currWord);
	}
	inFile.close();
	wordBank->reportAll(cout);


    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    cout << duration << endl;

    return 0;
}