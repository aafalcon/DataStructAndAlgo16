#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class AddStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_variableName2;
	int m_value;


public:
	AddStatement(std::string variableName, int value);
	AddStatement(std::string variableName, std::string variableName2);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif