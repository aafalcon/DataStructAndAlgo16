#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <vector>
#include <string>

class PrintallStatement: public Statement
{
public:
	PrintallStatement();

	virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif