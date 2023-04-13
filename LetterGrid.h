// Project 3 - Julian, Anwar, and David - LetterGrid Class .h
#include <iostream>
#include <string>
#include <fstream>
#include "d_matrix-1.h"
using namespace std;

class LetterGrid {
	public:
		// Grid matrix for storing letters
		matrix<string> grid;
		// Default Constructor: Grid length and width one
		LetterGrid();
		// Modified Constructor: Has grid length and width and character fill from file
		LetterGrid(string path);
		// Function: Loads letters from a file path 
		void LoadGridFromFile(string path);
		// Function: Prints grid into console
		void PrintGrid();
};