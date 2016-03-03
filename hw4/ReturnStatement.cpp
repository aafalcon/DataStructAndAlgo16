#include "ReturnStatement.h"
using namespace std;

ReturnStatement::ReturnStatement() {}

void ReturnStatement::execute(ProgramState * state, ostream &outf) {
	// If no return lines on stack, return behaves like an end statement
	if (state->retStackEmpty())
	{
		state->reachEnd();
		// increment program counter
		state->counterNext();
	}
	else
	{
		int returnLine= state->getReturn();
		state->counterJump(returnLine);
	}

}