#include "hash.h"
#include <cmath>
#include <vector>

using namespace std;

Hash::Hash() {
	loadFactor = 0;
	buckets = 11;
}

Hash::~Hash() {

}

void Hash::add(const std::string& word) {

}

void Hash::reportAll(std::ostream& output) {

}

int Hash::hash(string word) {
	int length = word.size();
	// convert string to base 128 number
	long long baseChar;
	vector<int> compact;
	long long temp = -1;
	int sigDigit;
	if (length <= 8)
	{
		for (int i=0; i<length; ++i)
		{
			baseChar += (long long)pow(128, length-i-1) * word[i];
		}
		// convert base 128 number to base 40961
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
	}
	else if (length > 8 && length <= 16)
	{
		// convert last 8 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-8)+i];
		}
		// convert base 128 number to base 40961
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
		baseChar = 0;
		// convert remaining letters
		for (int i=0; i<length-8; ++i)
		{
			baseChar += (long long)pow(128, (length-8)-i-1) * word[i];
		}
		temp = -1;
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
	}
	else if (length > 16 && length <= 24)
	{
		// convert last 8 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-8)+i];
		}
		// convert base 128 number to base 40961
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
		baseChar = 0;
		// convert last 16-8 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-16)+i];
		}
		temp = -1;
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
		// convert remaining letters
		for (int i=0; i<length-16; ++i)
		{
			baseChar += (long long)pow(128, (length-16)-i-1) * word[i];
		}
		temp = -1;
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
	}
	else
	{
		// convert last 8 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-8)+i];
		}
		// convert base 128 number to base 40961
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
		baseChar = 0;
		// convert last 16-8 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-16)+i];
		}
		temp = -1;
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
		// convert last 24-16 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-24)+i];
		}
		temp = -1;
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
		// convert remaining letters
		for (int i=0; i<length-24; ++i)
		{
			baseChar += (long long)pow(128, (length-24)-i-1) * word[i];
		}
		temp = -1;
		while (temp != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			temp = baseChar / 40961;
		}
	}
}

void Hash::resize() {

}