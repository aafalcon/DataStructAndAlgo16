#include "GosubStatement.h"
using namespace std;

GosubStatement::GosubStatement(int linenum):m_linenum(linenum) {}

void GosubStatement::execute(ProgramState * state, ostream &outf)
{
	// Error if line number provided is out of bounds
	if ((m_linenum <= 0) || (m_linenum > state->getNumLines()))
	{
		outf << "Illegal jump instruction" << endl;
		// make program terminate
		state->reachEnd();
		return;
	}
	
	//return line is 1 after GOSUB, and counter is 1 behind, so add 2
	int nextLine = state->getCounter() + 2;
	state->addReturn(nextLine);
	state->counterJump(m_linenum);
	
}