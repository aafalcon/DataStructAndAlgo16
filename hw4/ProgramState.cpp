#include "ProgramState.h"
using namespace std;

ProgramState::ProgramState(int numLines) {
	m_numLines= numLines;
}

void ProgramState::addVar(string varName, int varVal) {
	varList.insert(make_pair(varName, varVal));
}

void ProgramState::counterNext() {
	counter++;
}

int ProgramState::getNumLines() {
	return m_numLines;
}