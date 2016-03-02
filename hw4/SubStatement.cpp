#include "SubStatement.h"
using namespace std;

SubStatement::SubStatement(string variableName, int value) {
	m_variableName= variableName;
	// dummy variable if a variable name is not given
	m_variableName2= "dnexist";
	m_value= value;
}

SubStatement::SubStatement(string variableName, string variableName2) {
	m_variableName = variableName;
	m_variableName2 = variableName2;
}


void SubStatement::execute(ProgramState * state, ostream &outf) {
	int oldVal, newVal;
	oldVal = state->printVar(m_variableName);
	// if dummy variable, then there is value instead
	if (m_variableName2 == "dnexist")
	{
		newVal = oldVal - m_value;
	}
	// otherwise, find value of provided variable
	else
	{
		m_value = state->printVar(m_variableName2);
		newVal = oldVal - m_value;
	}

	state->modifyVar(m_variableName, newVal);

	// increment program counter
	state->counterNext();
}