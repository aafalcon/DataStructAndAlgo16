#include "MultStatement.h"
using namespace std;

MultStatement::MultStatement(string variableName, int value) {
	m_variableName= variableName;
	// dummy variable if a variable name is not given
	m_variableName2= "dnexist";
	m_value= value;
}

MultStatement::MultStatement(string variableName, string variableName2) {
	m_variableName = variableName;
	m_variableName2 = variableName2;
}


void MultStatement::execute(ProgramState * state, ostream &outf) {
	int oldVal, newVal;
	// if variable1 is not declared set value to 0
	if (!(state->varExists(m_variableName)))
	{
		state->addVar(m_variableName, 0);
	}

	oldVal = state->printVar(m_variableName);
	
	// if dummy variable, then there is value instead
	if (m_variableName2 == "dnexist")
	{
		newVal = oldVal * m_value;
	}
	// otherwise, find value of provided variable
	else
	{
		// if variable2 is not declared set value to 0
		if (!(state->varExists(m_variableName2)))
		{
			state->addVar(m_variableName2, 0);
		}

		m_value = state->printVar(m_variableName2);
		newVal = oldVal * m_value;
	}

	state->modifyVar(m_variableName, newVal);

	// increment program counter
	state->counterNext();
}