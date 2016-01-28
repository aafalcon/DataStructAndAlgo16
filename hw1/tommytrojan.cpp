#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  string ***trojans;
  string curr;

  input >> floors;
  trojans = new string**[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];

  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
  }
  //skip first line
  getline(input,curr);
  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) 
		  {
			  output << "Error - incorrect command" << endl;
		  }
		  // Error if floor i is out of range of total floors
		  else if ((i >= floors) || (i < 0))
		  {
		  	  output << "Error - floor " << i;
		  	  output << " does not exist" << endl;
		  }
		  // Error if there are no occupants on floor i
		  else if (floorsizes[i] != 0)
		  {
		  	  output << "Error - floor " << i;
		  	  output << " is not empty" << endl;
		  }
		  // Allocate memory for k students on floor i
		  else 
		  { 
		      trojans[i]= new string*[k];
		      for (int j=0; j<k; j++)
		      {
		      	  trojans[i][j]= NULL;
		      }
		      floorsizes[i]= k;
		  }
	  }
	  else if (curr == "MOVEOUT") {
	  	  int i;
	  	  ss >> i;
	  	  if (ss.fail()) 
	  	  {
			  output << "Error - incorrect command" << endl;
		  }
		  // Error if floor i is out of range of total floors
		  else if ((i >= floors) || (i < 0))
		  {
		  	  output << "Error - floor " << i;
		  	  output << " does not exist" << endl;
		  }
		  // Error if there are 0 students on floor i
		  else if (floorsizes[i] == 0)
		  {
		  	  output << "Error - floor " << i;
		  	  output << " is empty" << endl;
		  }
		  else
		  {
		  	  // Deallocate memory for floor i
		  	  for (int j=0; j<floorsizes[i]; j++)
		  	  {
		  	  	  delete [] trojans[i][j];
		  	  }
		  	  // Reset floor size
		  	  floorsizes[i]= 0;
		  }
	  }
	  else if (curr == "OBTAIN") {
	  	  int i,j,k;
		  ss >> i;
		  ss >> j;
		  ss >> k;
		  if (ss.fail()) 
		  {
			  output << "Error - incorrect command" << endl;
		  }
		  // Error if student j is out of range of total students
		  else if ((j >= floorsizes[i]) || (j < 0))
		  {
		  	  output << "Error - there is no student " << j;
		  	  output << " on floor " << i << endl;
		  }
		  // Error if student j already has memory allocated for
		  // his/her possessions
		  else if (trojans[i][j] != NULL)
		  {
		  	  output << "Error - student " << j;
		  	  output << " already has possessions" << endl;
		  }
		  // Allocate memory for possessions
		  else
		  {
		  	  trojans[i][j]= new string[k+1];
		  	  // First element in array is the # of possessions
		  	  // Converting this # into a string with stringstream
		  	  stringstream ss2;
		  	  string poss;
		  	  ss2 << k;
		  	  ss2 >> poss;
		  	  trojans[i][j][0]= poss;
		  	  for (int it=1; it<=k; it++)
		  	  {
		  	  	  // Assign all the possesions starting at index 1
		  	  	  ss >> poss;
		  	  	  trojans[i][j][it]= poss;
		  	  }
		  }
	  }
	  else if (curr == "OUTPUT") {
	  	  int i,j;
		  ss >> i;
		  ss >> j;
		  if (ss.fail()) 
		  {
			  output << "Error - incorrect command" << endl;
		  }
		  // Error if student j is out of range of total students
		  else if ((j >= floorsizes[i]) || (j < 0))
		  {
		  	  output << "Error - there is no student " << j;
		  	  output << " on floor " << i << endl;
		  }
		  // Error if student j doesn't have memory allocated for
		  // his/her possessions
		  else if (trojans[i][j] == NULL)
		  {
		  	  output << "Error - student " << j;
		  	  output << " has no possessions" << endl;
		  }
		  // Print student's possessions to output
		  else
		  {
		  	  stringstream ss2;
		  	  int numPoss;
		  	  output << "Possessions of student " << j;
		  	  output << " living on floor " << i << ":" << endl; 
		  	  // Convert # of possesions from string back to int
		  	  ss2 << trojans[i][j][0];
		  	  ss2 >> numPoss;
		  	  for (int k=1; k<=numPoss; k++)
		  	  {
		  	  	  output << trojans[i][j][k] << endl;
		  	  }
		  }
	  }
	  // Error if command is not recognized
	  else {
	  	  output << "Error - incorrect command" << endl;
	  }
  }
  
  // Deallocate all memory
  for (int i=0; i<floors; i++)
  {
  	  for (int j=0; j<floorsizes[i]; j++)
 	  {
  	      delete [] trojans[i][j];
  	  }
  	  delete [] trojans[i];
  }
  delete [] trojans;

  delete [] floorsizes;
  
  return 0;
}
