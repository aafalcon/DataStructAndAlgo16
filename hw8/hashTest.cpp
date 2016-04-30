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

	h->add("the");
	h->add("tragedy");
	h->add("hamlet");
	h->add("boy");
	h->add("alpha");
	h->add("bravo");

	h->add("charlie");
	h->add("delta");
	h->add("echo");
	h->add("epsilon");
	h->add("foxtrot");
	h->add("alden");
	h->add("billie");
	h->add("tony");
	h->add("daredevil");
	h->reportAll(cerr);
	h->add("trainwreck");




	h->reportAll(cerr);

	return 0;
}