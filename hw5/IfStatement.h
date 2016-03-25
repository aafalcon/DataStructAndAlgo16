#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class IfStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_oper;
	int m_value;
	int m_linenum;

public:
	IfStatement(std::string variableName, std::string oper, 
		        int value, int linenum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif