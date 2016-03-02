// PrintStatement.cpp:
#include "PrintStatement.h"
using namespace std;

PrintStatement::PrintStatement(string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, ostream &outf)
{
	// pull value of variable from state
	int currVal;
	currVal = state->printVar(m_variableName);
	// push to ostream
	outf << currVal << endl;
	// increment program counter
	state->counterNext();
}


