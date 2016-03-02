// LetStatement.cpp:
#include "LetStatement.h"
using namespace std;

LetStatement::LetStatement(string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, ostream &outf)
{
	// check if variable is already in map
	if (state->varExists(m_variableName))
	{
		// if so change value of existing variable
		state->modifyVar(m_variableName, m_value);
	}
	else
	{
		// or add new variable
		state->addVar(m_variableName, m_value);
	}
	// increment program counter
	state->counterNext();
}


