// PrintStatement.cpp:
#include "PrintStatement.h"
using namespace std;

PrintStatement::PrintStatement(string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, ostream &outf)
{
	// if variable is not declared set value to 0
	if (!(state->varExists(m_variableName)))
	{
		state->addVar(m_variableName, 0);
	}
	// pull value of variable from state
	int currVal;
	currVal = state->printVar(m_variableName);
	// push to ostream
	outf << currVal << endl;
	// increment program counter
	state->counterNext();
}


