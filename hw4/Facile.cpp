// Facile.cpp
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
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <iostream>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter Facile program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var, var2, oper, dummy;
	int val, lineNum;

	ss << line;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		
		// if no specific value is set, make value 0
		if(!(ss >> val))
		{
			val= 0;
		}
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	else if ( type == "PRINT" )
	{
		ss >> var;
		statement = new PrintStatement(var);
	}

	else if ( type == "PRINTALL")
	{
		statement = new PrintallStatement();
	}

	else if ( (type == "END") || (type == ".") )
	{
		statement = new EndStatement();
	}

	else if ( type == "ADD" )
	{
		ss >> var;
		ss >> var2;

		// check if var2 is an integer
		if (isdigit(var2[0]))
		{
			// change string to int
			val = atoi(var2.c_str());
			statement = new AddStatement(var, val);
		}
		// otherwise, var2 is a variable name and must call other constructor
		else
		{
			statement = new AddStatement(var, var2);
		}
	}

	else if ( type == "SUB" )
	{
		ss >> var;
		ss >> var2;

		// check if var2 is an integer
		if (isdigit(var2[0]))
		{
			// change string to int
			val = atoi(var2.c_str());
			statement = new SubStatement(var, val);
		}
		// otherwise, var2 is a variable name and must call other constructor
		else
		{
			statement = new SubStatement(var, var2);
		}
	}

	else if ( type == "MULT" )
	{
		ss >> var;
		ss >> var2;

		// check if var2 is an integer
		if (isdigit(var2[0]))
		{
			// change string to int
			val = atoi(var2.c_str());
			statement = new MultStatement(var, val);
		}
		// otherwise, var2 is a variable name and must call other constructor
		else
		{
			statement = new MultStatement(var, var2);
		}
	}

	else if ( type == "DIV" )
	{
		ss >> var;
		ss >> var2;

		// check if var2 is an integer
		if (isdigit(var2[0]))
		{
			// change string to int
			val = atoi(var2.c_str());
			statement = new DivStatement(var, val);
		}
		// otherwise, var2 is a variable name and must call other constructor
		else
		{
			statement = new DivStatement(var, var2);
		}
	}
	
	else if ( type == "GOTO" )
	{
		ss >> lineNum;
		statement = new GotoStatement(lineNum);
	}

	else if ( type == "IF")
	{
		ss >> var; // variable to compare
		ss >> oper; // comparison operator
		ss >> val; // interger value to compare to
		ss >> dummy; // THEN staement
		ss >> lineNum; // line to jump to

		statement = new IfStatement(var, oper, val, lineNum);
	}
	// Incomplete;  TODO:  Finish this function!

		
	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );
	int numLines= program.size() - 1;
	ProgramState* state = new ProgramState(numLines);
	int i;

	while (!(state->getEndReached()))
	{
		i = state->getCounter();
		program[i+1]->execute(state, outf);
	}
	
	// Incomplete;  TODO:  Finish this function!
}

