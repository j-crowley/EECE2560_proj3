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
	int inputLen;
	int inputWid;
	string inputStr;
	// Grid Resizing
	fin >> inputLen;
	fin >> inputWid;
	grid.resize(inputLen, inputWid);
	// Grid Loading
	for (int x = 0; x < inputLen; x++){
		for (int y = 0; y < inputWid; y++){
			fin >> grid[x][y];
		}
	}
}

void LetterGrid::PrintGrid(){
	cout << "Grid: \n";
	for (int x = 0; x < grid.cols();  x++){
		for (int y = 0; y < grid.rows(); y++){
			cout << grid[x][y] << " ";
		}
		cout << "\n";
	}
}
