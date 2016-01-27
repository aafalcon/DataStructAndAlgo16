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
		  else if (floorsizes[i] != 0)
		  {
		  	  output << "Error - floor " << i;
		  	  output << " is not empty" << endl;
		  }
		  else if ((i >= floors) || (i < 0))
		  {
		  	  output << "Error - floor " << i;
		  	  output << " does not exist" << endl;
		  }
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
		  else if (floorsizes[i] == 0)
		  {
		  	  output << "Error - floor " << i;
		  	  output << " is empty" << endl;
		  }
		  else if ((i >= floors) || (i < 0))
		  {
		  	  output << "Error - floor " << i;
		  	  output << " does not exist" << endl;
		  }
		  else
		  {
		  	  for (int j=0; j<floorsizes[i]; j++)
		  	  {
		  	  	  delete [] trojans[i][j];
		  	  }
		  	  delete [] trojans[i];
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
		  else if ((j >= floorsizes[i]) || (j < 0))
		  {
		  	  output << "Error - there is no student " << j;
		  	  output << " on floor " << i << endl;
		  }
		  else if (trojans[i][j] != NULL)
		  {
		  	  output << "Error - student " << j;
		  	  output << " already has possessions" << endl;
		  }
		  else
		  {
		  	  trojans[i][j]= new string[k+1];
		  	  string item;
		  	  trojans[i][j][0]= k;
		  	  for (int it=1; it<=k; it++)
		  	  {
		  	  	  ss >> item;
		  	  	  trojans[i][j][it]= item;
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
		  else if ((j >= floorsizes[i]) || (j < 0))
		  {
		  	  output << "Error - there is no student " << j;
		  	  output << " on floor " << i << endl;
		  }
		  else if (trojans[i][j] == NULL)
		  {
		  	  output << "Error - student " << j;
		  	  output << " has no possessions" << endl;
		  }
		  else
		  {
		  	  int numItems= trojans[i][j][0];
		  	  for (int k=1; k<=numItems; k++)
		  	  {
		  	  	  output << trojans[i][j][k] << endl;
		  	  }
		  }
	  }
	  else {
	  	  output << "Error - incorrect command" << endl;
	  }
  }
  
  //Deallocate all memory
  for (int i=0; i<floors; i++)
  {
  	  for (int j=0; j<floorsizes[i]; j++)
 	  {
  	      delete [] trojans[i][j];
  	  }
  	  delete [] trojans[i];
  }
  delete [] trojans;
  
  return 0;
}
