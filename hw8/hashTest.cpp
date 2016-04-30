#include "hash.h"
#include <iostream>
#include <string>

using namespace std;

int main () 
{
	Map* h = new Hash();

	h->add("bob");
	h->add("george");
	h->add("puppies");
	h->add("bee");
	h->add("shishkabob");
	h->add("superhero");
	h->add("alden");
	h->add("blue");
	h->add("george");


	h->reportAll(cerr);

	return 0;
}