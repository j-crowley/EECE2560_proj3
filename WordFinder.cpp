// Project 3 - Julian, Anwar, and David - Wordfinder Class .cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sort_algorithms.h"
#include "WordFinder.h"
using namespace std;

// Implementation
// Constructors
WordFinder::WordFinder(){}

WordFinder::WordFinder(string path){
	WordsFromFile(path);
}

// Functions
void WordFinder::WordsFromFile(string path){
	ifstream fin;
	fin.open(path);
	string inputStr;
	while (fin >> inputStr){
		words.push_back(inputStr);
	}
}

ostream & WordFinder::operator<<(ostream & out){
	for(string word : words){
		out << word << "\n";
	}
	return out;
}

void WordFinder::SelectionSortWords(){
	selectionSort(words);
}

bool WordFinder::LookUpWord(string wordStr){
	int mid, first = 0, last = words.size() - 1;
	while ( first <= last ) {
		mid = ( first + last ) / 2;
		if ( wordStr < words[mid] ) {
			last = mid - 1;
		} else if ( wordStr > words[mid] ) {
			first = mid + 1;
		} else {
			return true;
		}
		if ( first > last ) {
			return false;
		}
	}
	return false;
}

