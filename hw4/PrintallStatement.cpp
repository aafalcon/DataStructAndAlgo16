#include "PrintallStatement.h"
using namespace std;

PrintallStatement::PrintallStatement() {}


void PrintallStatement::execute(ProgramState * state, ostream &outf)
{
	state->printAll(outf);
	// increment program counter
	state->counterNext();
}