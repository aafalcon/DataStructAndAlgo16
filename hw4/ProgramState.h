// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

//#include "stackint.h"
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class ProgramState
{
public:
	ProgramState(int numLines);
	void addVar(std::string varName, int varVal);
	void modifyVar(std::string varName, int varVal);
	void reachEnd();
	bool varExists(std::string varName);
	void counterNext();
	void counterJump(int line);
	int getNumLines();
	int getCounter();
	int printVar(std::string varName);
	void printAll(std::ostream &outf);
	bool getEndReached();
	void addReturn(int line);
	int getReturn();
	bool retStackEmpty();

	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.


private:
	int m_numLines;
	int counter;
	std::map<std::string, int> varMap;
	std::map<std::string, int>::iterator it;
	std::stack<int> rtrnLines;
	bool endReached;
};

#endif



