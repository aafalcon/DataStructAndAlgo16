#include "ProgramState.h"
using namespace std;

ProgramState::ProgramState(int numLines) {
	m_numLines= numLines;
	counter= 0;
	endReached= false;
}

void ProgramState::addVar(string varName, int varVal) {
	varMap.insert(make_pair(varName, varVal));
}

void ProgramState::modifyVar(std::string varName, int varVal) {
	varMap[varName] = varVal;
}

void ProgramState::reachEnd() {
	endReached = true;
}

bool ProgramState::varExists(string varName) {
	it= varMap.find(varName);
	if (it != varMap.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ProgramState::counterNext() {
	counter++;
}

void ProgramState::counterJump(int line) {
	// counter is one behind line number
	counter = line-1;
}

int ProgramState::getNumLines() {
	return m_numLines;
}

int ProgramState::getCounter() {
	return counter;
}

int ProgramState::printVar(string varName) {
	return varMap[varName];
}

void ProgramState::printAll(ostream &outf) {
	// iterate through map
	for(it = varMap.begin(); it != varMap.end(); ++it)   
	{
	    // create line with variable name and value
	    outf << it->first << " " << it->second << endl;
	}
}

bool ProgramState::getEndReached() {
	return endReached;
}