#include "EndStatement.h"
using namespace std;

EndStatement::EndStatement() {}

void EndStatement::execute(ProgramState * state, ostream &outf) {
	state->reachEnd();
	// increment program counter
	state->counterNext();
}