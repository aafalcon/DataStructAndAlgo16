#include "splTree.h"
#include <iostream>
#include <string>

using namespace std;

int main () 
{
	Map* spl = new SplayTree<string,int>();
	spl->add("Charlie");
	spl->reportAll(cout);
	spl->add("Alpha");
	spl->reportAll(cout);
	spl->add("Bravo");
	spl->reportAll(cout);
	spl->add("Alpha");
	spl->reportAll(cout);
	spl->add("Delta");
	spl->reportAll(cout);
	spl->add("Delta");
	spl->reportAll(cout);
	spl->add("Echo");
	spl->reportAll(cout);
	spl->add("Aaron");
	spl->reportAll(cout);
	spl->add("echo");
	spl->reportAll(cout);


	return 0;
}