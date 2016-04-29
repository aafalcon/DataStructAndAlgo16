#include "hash.h"
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

Hash::Hash() {
	loadFactor = 0;
	items = 0;
	buckets = 11;
	hashTable.reserve(11, NULL);
}

Hash::~Hash() {
	for (vector<pair<string,int> >::iterator it = hashTable.begin(); 
		it != hashTable.end(); ++it)
	   {
	     delete *it;
	   } 
   	hashTable.clear();
}

void Hash::add(const string& word) {
	// change uppercase characters to lowercase
	std::string word1 = word; // copy word to edit
	for (int i=0; i < word1.length(); ++i)
	{
		// get ASCII value of character
		int letter = (int)word1[i];
		int newLetter;
		if (letter >= 65 && letter <= 90)
		{
			newLetter = letter + 32;
			word1[i] = (char)newLetter;
		}
	}
	// quadratic probing
	bool foundEmpty = false;
	int wordCount;
	int quadIter = 0;
	int i = 0;
	while (!foundEmpty)
	{
		if (hashTable[hashWord(word1)+i] == NULL)
		{
			// place new word into empty spot
			pair<string, int> value = make_pair(word1, 1)
			*hashTable[hashWord(word1)+i] = value;
			foundEmpty = true;
			items++;
		}
		else
		{
			// If spot isn't empty, check if it is same word
			if ((*hashTable[hashWord(word1)+i]).first == word1)
			{
				wordCount = (*hashTable[hashWord(word1)+i]).second;
				(*hashTable[hashWord(word1)+i]).second = wordCount + 1;
				foundEmpty = true;
			}
			else
			{
				quadIter++;
				i = pow(quadIter, 2);
			}
		}
	}

	loadFactor = items / buckets;

	if (loadFactor > 0.5)
	{
		resize();
	}
}

void Hash::reportAll(ostream& output) {
	for (int i=0; i < hashTable.capacity(); ++i)
	{
		if (hashTable[i] != NULL)
		{
			output << (*hashTable[i]).first << " ";
			output << (*hashTable[i]).second << endl;
		}
	}
}

int Hash::hashWord(string word) {
	int length = word.size();
	// convert string to base 128 number
	long long baseChar = 0;
	vector<long long> compact;
	long long sigDigit = 0;

	if (length <= 8)
	{
		for (int i=0; i<length; ++i)
		{
			baseChar += (long long)pow(128, length-i-1) * word[i];
		}
		// convert base 128 number to base 40961
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// make the remaining digits in word 0
		while (compact.size() != 14)
		{
			compact.push_back(0);
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
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// convert remaining letters
		for (int i=0; i<length-8; ++i)
		{
			baseChar += (long long)pow(128, (length-8)-i-1) * word[i];
		}
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// make the remaining digits in word 0
		while (compact.size() != 14)
		{
			compact.push_back(0);
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
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// convert last 16-8 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-16)+i];
		}
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		baseChar = 0;
		// convert remaining letters
		for (int i=0; i<length-16; ++i)
		{
			baseChar += (long long)pow(128, (length-16)-i-1) * word[i];
		}
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// make the remaining digits in word 0
		while (compact.size() != 14)
		{
			compact.push_back(0);
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
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// convert last 16-8 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-16)+i];
		}
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// convert last 24-16 letters
		for (int i=0; i<8; ++i)
		{
			baseChar += (long long)pow(128, 7-i) * word[(length-24)+i];
		}
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// convert remaining letters
		for (int i=0; i<length-24; ++i)
		{
			baseChar += (long long)pow(128, (length-24)-i-1) * word[i];
		}
		while (baseChar != 0)
		{
			sigDigit = baseChar % 40961;
			compact.push_back(sigDigit);
			baseChar = baseChar / 40961;
		}
		// make the remaining digits in word 0
		while (compact.size() != 14)
		{
			compact.push_back(0);
		}
	}

	int result = (34394 * compact[13] + 36706 * compact[12] + 38074 * compact[11]
		+ 16351 * compact[10] + 2623 * compact[9] + 10174 * compact[8] 
		+ 22339 * compact[7] + 27779 * compact[6] + 36642 * compact[5] 
		+ 19250 * compact[4] + 36216 * compact[3] + 33514 * compact[2] 
		+ 24019 * compact[1] + 5552 * compact[0]) % buckets;
	
	compact.clear();
	return result;
}

void Hash::resize() {
	if (buckets == 11)
	{
		buckets = 23;
	}
	else if (buckets == 23)
	{
		buckets = 41;
	}
	else if (buckets == 41)
	{
		buckets = 83;
	}
	else if (buckets == 83)
	{
		buckets = 163;
	}
	else if (buckets == 163)
	{
		buckets = 331;
	}
	else if (buckets == 641)
	{
		buckets = 1283;
	}
	else if (buckets == 1283)
	{
		buckets = 2579;
	}
	else if (buckets == 2579)
	{
		buckets = 5147;
	}
	else if (buckets == 5147)
	{
		buckets = 10243;
	}
	else if (buckets == 10243)
	{
		buckets = 20483;
	}
	else
	{
		buckets = 40961;
	}

	loadFactor = items / buckets;
	hashTable.reserve(buckets, NULL);
}

void Hash::rehash {
	// Make a copy of the current hash table

	// Resize current 
}