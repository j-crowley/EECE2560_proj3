// Project 3 - Julian, Anwar, and David - LetterGrid Class .h
#ifndef _LETTER_GRID
#define _LETTER_GRID

#include <iostream>
#include <string>
#include <fstream>
#include "d_matrix-1.h"
using namespace std;

class LetterGrid {
	public:
		// Grid matrix for storing letters
		matrix<string> grid;
		// Default Constructor: Grid length and width equal to one
		LetterGrid();
		// Modified Constructor: Resizes grid and fills with characters based on file
		LetterGrid(string path);
		// Function: Loads and resizes grid from a file using file path 
		void LoadGridFromFile(string path);
		// Function: Prints grid into console
		void PrintGrid();
};

#endif