// Project 33 - David, Anwar, and Julian - Wordfinder Class .h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sort_algorithms.h"
using namespace std;

class WordFinder {
	private:
		vector<string> words;
	
	public:
		// Default Constructor
		WordFinder();
		// Modified Constructor: Loads from file and Sorts
		WordFinder(string path);
		// Function: Loads words from file to vector
		void WordsFromFile(string path);
		// Operator Overide: << contents of string vector words
		ostream & operator<< (ostream & out);
		// Function: Sorts words using selection sort in sort_algorithms.h
		void SortWords();
		// Function: Looks up word using binary search on vector
		bool LookUpWord(string wordStr);
};