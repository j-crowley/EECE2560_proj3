// Project 3 - Julian, Anwar, and David - LetterGrid Class .cpp
#include <iostream>
#include <string>
#include <fstream>
#include "d_matrix-1.h"
#include "LetterGrid.h"
using namespace std;

//Implementation
//Constuctors
LetterGrid::LetterGrid(){
	grid.resize(1,1);
}

LetterGrid::LetterGrid(string path){
	grid.resize(1,1);
	LoadGridFromFile(path);
}

// Functions
void LetterGrid::LoadGridFromFile(string path){
	ifstream fin;
	fin.open(path);
	// Checking if path exists
	if (!fin){
		cerr << "Cannot open letter grid input file.\n";
        exit(1);
	}
	int inputLen;
	int inputWid;
	string inputStr;
	// Grid Resizing
	fin >> inputLen;
	fin >> inputWid;
	grid.resize(inputLen, inputWid);
	// Grid Loading 
	for (int y = 0; y < inputWid; y++){
		for (int x = 0; x < inputLen; x++){
			fin >> grid[y][x];
		}
	}
}

void LetterGrid::PrintGrid(){
	cout << "Grid: \n"; 
	for (int y = 0; y < grid.rows(); y++){
		for (int x = 0; x < grid.cols();  x++){
			cout << grid[y][x] << " ";
		}
		cout << "\n";
	}
}
