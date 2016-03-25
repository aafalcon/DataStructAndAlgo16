#include "IfStatement.h"
using namespace std;

IfStatement::IfStatement(string variableName, string oper, int value,
                         int linenum) 
{
	m_variableName = variableName;
	m_oper = oper;
	m_value = value;
	m_linenum = linenum;
}

void IfStatement::execute(ProgramState * state, ostream &outf)
{
	bool trueCond = false;
	int toCompare;

	// if variable1 is not declared set value to 0
	if (!(state->varExists(m_variableName)))
	{
		state->addVar(m_variableName, 0);
	}
	toCompare = state->printVar(m_variableName);

	// check to see which operator is used, then see if it makes condition true
	if (m_oper == "<")
	{
		if (toCompare < m_value)
		{
			trueCond = true;
		}
	}
	else if (m_oper == "<=")
	{
		if (toCompare <= m_value)
		{
			trueCond = true;
		}
	}
	else if (m_oper == ">")
	{
		if (toCompare > m_value)
		{
			trueCond = true;
		}
	}
	else if (m_oper == ">=")
	{
		if (toCompare >= m_value)
		{
			trueCond = true;
		}
	}
	else if (m_oper == "=") // equal to
	{
		if (toCompare == m_value)
		{
			trueCond = true;
		}
	}
	else if (m_oper == "<>") // not equal to
	{
		if (toCompare != m_value)
		{
			trueCond = true;
		}
	}

	// do line jump if condition is true
	if (trueCond)
	{
		// Error if line number provided is out of bounds
		if ((m_linenum <= 0) || (m_linenum > state->getNumLines()))
		{
			outf << "Illegal jump instruction" << endl;
			// make program terminate
			state->reachEnd();
			return;
		}
		state->counterJump(m_linenum);
	}
	else
	{
		// increment program counter
		state->counterNext();
	}
}