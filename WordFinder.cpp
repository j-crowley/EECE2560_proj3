// Project 33 - David, Anwar, and Julian - Wordfinder Class .cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "sort_algorithms.h"
#include "WordFinder.h"
using namespace std;

// Implementation
// Constructors
WordFinder::WordFinder(){}

WordFinder::WordFinder(string path){
	WordsFromFile(path);
	SortWords();
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

ostream & WordFinder::operator<< (ostream & out){
	for(string word : words){
		out << word << "\n";
	}
	return out;
}

void WordFinder::SortWords(){
	selectionSort(words);
}

bool WordFinder::LookUpWord(string wordStr){
	if(binary_search(words.begin(),words.end(),wordStr)){
		return true;
	}
	return false;
}
