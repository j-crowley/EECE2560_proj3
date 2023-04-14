// Project 3 - Julian, Anwar, and David - Wordfinder Class .h
#ifndef _WORD_FINDER
#define _WORD_FINDER

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "sort_algorithms.h"
using namespace std;

class WordFinder {
private:
    vector<string> words;

public:
    // Default Constructor
    WordFinder();
    // Modified Constructor: Loads from file
    WordFinder(string path);
    // Function: Loads words from file to vector
    void WordsFromFile(string path);
    // Function: Sorts words using selection sort in sort_algorithms.h
    void SelectionSortWords();
    // Function: Sorts words using quick sort in sort_algorithms.h
    void QuickSortWords();
    // Function: Sorts words using heap sort in sort_algorithms.h
    void HeapSortWords();
    // Function: Looks up word using binary search on vector
    bool LookUpWord(string wordStr);
    // Operator Overide: << contents of string vector words
    friend ostream & operator<<(ostream & out, WordFinder & WF);
};

#endif