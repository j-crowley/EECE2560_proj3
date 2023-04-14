// Project 3 - Julian, Anwar, and David - Wordfinder Class .cpp
#include <iostream>
#include <vector>
#include <cstdlib>
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
    WordsFromFile(path.c_str());
}

// Functions
void WordFinder::WordsFromFile(string path){
    ifstream fin;
    fin.open(path.c_str());
    if (!fin){
        cerr << "Cannot open word finder input file.\n";
        exit(1);
    }
    string inputStr;
    while (fin >> inputStr){
        words.push_back(inputStr);
    }
}

ostream & operator<<(ostream & out, WordFinder & WF){
    for(int x = 0; x < WF.words.size(); x++){
        out << WF.words[x] << "\n";
    }
    return out;
}

void WordFinder::SelectionSortWords(){
    selectionSort(words);
}

void WordFinder::QuickSortWords() {
    quickSort(words, 0, int(words.size())-1);
}

void WordFinder::HeapSortWords() {
    heapSort(words);
}

bool WordFinder::LookUpWord(string wordStr){
    if (binary_search(words.begin(),words.end(),wordStr)){
        return true;
    }
    return false;
}



