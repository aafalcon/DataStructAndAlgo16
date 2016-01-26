/**
 * Incorrect code to identify palindromes
 */

#include <iostream>
#include <sstream>
#include <cstring> 

using namespace std;

bool helper(stringstream &input, int len)
{
	char prev;

	//if we are at the midpoint of the string, return true.
	if (len == 0) return true;

	/**
	 * If the length of the string is odd, and the next
	 * character is the midpoint of the string, consume it
	 * and return true.
	 */
	input >> prev;
	if (len == 1) return true;

	bool val = helper(input, len-2);

	//make your changes below this line.
	if (val) 
	{
		/*
		* Cursor in the stringstream is past the middle and all 
		* of the letters from the first half have been saved in 
		* prev for each recursive call. So, we can just keep
		* using >> to check every character in the 2nd half.
		*/
		char mirror;
		input >> mirror;

		if (prev == mirror) return true;
		else return false;
	}
	else
	{
		return false;
	}
	
}

//do not change the main function.
int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a string of characters." << endl;
    return 1;
  }
  stringstream ss;
  ss << argv[1];
  if(helper(ss, strlen(argv[1])))
	  cout << "Palindrome" << endl;
  else cout << "Not a Palindrome" << endl;
  return 0;
}
