#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class DivStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_variableName2;
	int m_value;


public:
	DivStatement(std::string variableName, int value);
	DivStatement(std::string variableName, std::string variableName2);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif