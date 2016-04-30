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
    else
    {
    	wordBank = new Hash();
    }
    while (!inFile.eof())
	{
		inFile >> currWord;
		wordBank->add(currWord);
		//wordBank->reportAll(cerr);
	}
	wordBank->reportAll(cout);


    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    cout << duration << endl;

    return 0;
}