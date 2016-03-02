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

int ProgramState::getNumLines() {
	return m_numLines;
}

int ProgramState::getCounter() {
	return counter;
}

int ProgramState::printVar(string varName) {
	return varMap[varName];
}

vector<string> ProgramState::printAll() {
	vector<string> varList;
	string varPair;
	// iterate through map
	for(it = varMap.begin(); it != varMap.end(); ++it)   
	{
	    // create line with variable name and value
	    varPair = it->first;
	    varPair += " ";
	    varPair += it->second;
	    // push line into vector
	    varList.push_back(varPair);
	}
	return varList;
}

bool ProgramState::getEndReached() {
	return endReached;
}