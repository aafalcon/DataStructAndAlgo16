#ifndef FACILE_H
#define FACILE_H

#include "Statement.h"
#include "ProgramState.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "PrintallStatement.h"
#include "EndStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "GotoStatement.h"
#include "IfStatement.h"
#include "GosubStatement.h"
#include "ReturnStatement.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <iostream>


class Facile {
private:
	std::vector<std::string> codeLines;
	std::vector<Statement *> program;
	bool* breakpoints;
	int numLines, currLine;
	ProgramState* state;
public:
	Facile(std::istream& inf);
	~Facile();
	// parseProgram() takes a filename as a parameter, opens and reads the
	// contents of the file, and returns an vector of pointers to Statement.
	void parseProgram(std::istream& inf, std::vector<Statement *> & program);

	// parseLine() takes a line from the input file and returns a Statement
	// pointer of the appropriate type.  This will be a handy method to call
	// within your parseProgram() method.
	Statement * parseLine(std::string line);

	// interpretProgram() reads a program from the given input stream
	// and interprets it, writing any output to the given output stream.
	// Note:  you are required to implement this function!
	void executeProgram(std::ostream& outf);
	void executeLine(std::ostream& outf);
	std::string getLine(int lineNum);
	int getNumLines();
	std::string printIndex(int varIndex);
	int getNumVar();
	void addBreakpoint(int lineNum);
	bool breakExist(int lineNum);
};



#endif