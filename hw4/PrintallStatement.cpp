#include "PrintallStatement.h"
using namespace std;

PrintallStatement::PrintallStatement() {}


void PrintallStatement::execute(ProgramState * state, ostream &outf)
{
	vector<string> varList;
	varList = state->printAll();
	int numVar = varList.size();
	for (int i=0; i<numVar; ++i)
	{
		outf << varList[i] << endl;
	}

	// increment program counter
	state->counterNext();
}