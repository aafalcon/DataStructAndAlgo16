// Facile.cpp
#include "Facile.h"

using namespace std;

/*
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
*/
Facile::Facile(istream& inf) {
	parseProgram( inf, program );
	numLines= program.size() - 1;
	breakpoints = new bool[numLines];
	for (int i=0; i<numLines; ++i)
	{
		*(breakpoints+i) = false;
	}
	state = new ProgramState(numLines);
	currLine = 0;
}

Facile::~Facile() {
	// Deallocate memory
	for (int i=0; i<=numLines; ++i)
	{
		delete program[i];
	}
	delete state;
}

void Facile::parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		codeLines.push_back(line);
		program.push_back( parseLine( line ) );
	}

	numLines = program.size()-1;
}

Statement * Facile::parseLine(string line)
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

	else if ( type == "GOSUB")
	{
		ss >> lineNum;
		statement = new GosubStatement(lineNum);
	}

	else if ( type == "RETURN" )
	{
		statement = new ReturnStatement();
	}
	
	return statement;
}


void Facile::executeProgram(ostream& outf)
{
	while (!(state->getEndReached()) && !(this->breakExist(currLine)))
	{
		program[currLine+1]->execute(state, outf);
		currLine = state->getCounter();
	}

	// Reset program to beginning when end is reached
	if (state->getEndReached())
	{
		currLine = 0;
		state->restart();
		state->clearMap();
	}
}

void Facile::executeLine(ostream& outf)
{
	program[currLine+1]->execute(state, outf);
	currLine = state->getCounter();

	// Reset program to beginning when end is reached
	if (state->getEndReached())
	{
		currLine = 0;
		state->restart();
		state->clearMap();
	}
}

string Facile::getLine(int lineNum) {
	return codeLines[lineNum];
}

int Facile::getNumLines() {
	return numLines;
}

string Facile::printIndex(int varIndex) {
	// go to method in ProgramState
	return state->printIndex1(varIndex);
}

int Facile::getNumVar() {
	// go to method in ProgramState
	return state->getNumVar1();
}

void Facile::addBreakpoint(int lineNum) {
	if (*(breakpoints+lineNum) == false)
	{
		*(breakpoints+lineNum) = true;
	}
	else
	{
		*(breakpoints+lineNum) = false;
	}
}

bool Facile::breakExist(int lineNum) {
	return *(breakpoints+lineNum);
}