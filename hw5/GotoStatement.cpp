#include "GotoStatement.h"
using namespace std;

GotoStatement::GotoStatement(int linenum):m_linenum(linenum) {}

void GotoStatement::execute(ProgramState * state, ostream &outf)
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