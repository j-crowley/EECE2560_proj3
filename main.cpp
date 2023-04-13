// Project 3 - Julian, Anwar, and David - main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "LetterGrid.h"
#include "WordFinder.h"
using namespace std;

// Function: Finds all available combinations of words in the LetterGrid object
//			 and prints them out if they are in the glossary
// Precondition: WordFinder must be sorted
void matchWords (WordFinder glossary, LetterGrid wsearch){
	// Double for loop for each entry in grid
	for (int y = 0; y < wsearch.grid.rows(); y++){
		for (int x = 0; x < wsearch.grid.cols(); x++){
			// Loop for each word combo after inital word
			vector<string> gridWords (8,wsearch.grid[y][x]);
			for (int i = 1; i < wsearch.grid.rows(); i++){
				// Handles creating and checking all words originating x,y pos in each direction
				int col = wsearch.grid.cols();
				int row = wsearch.grid.rows();
				// Using modulo operation to handle wrap-around for the grid
				gridWords[0].append(wsearch.grid[(y + i % row + row) % row][(x % col + col) % col]);
				gridWords[1].append(wsearch.grid[(y - i % row + row) % row][(x % col + col) % col]);
				gridWords[2].append(wsearch.grid[(y % row + row) % row][(x + i % col + col) % col]);
				gridWords[3].append(wsearch.grid[(y % row + row) % row][(x - i % col + col) % col]);
				gridWords[4].append(wsearch.grid[(y + i % row + row) % row][(x + i % col + col) % col]);
				gridWords[5].append(wsearch.grid[(y - i % row + row) % row][(x - i % col + col) % col]);
				gridWords[6].append(wsearch.grid[(y + i % row + row) % row][(x - i % col + col) % col]);
				gridWords[7].append(wsearch.grid[(y - i % row + row) % row][(x + i % col + col) % col]);
				// Loop for checking each grid word in glossary
				if (i >= 4){
					for(int j = 0; j < gridWords.size(); j++){
						if (glossary.LookUpWord(gridWords[j])){
							cout << "Found: pos_x( " << x << " ), pos_y( " << y << " ) ";
							cout << "--> " << gridWords[j] << "\n";
						}
					} // End checking loop
				}
			} // End word combo loop
		}
	} // End grid double loop
} // End matchWords

// Function: Handles entire word search process and ask users for approriate inputs
void wordSearch (){
	// Setting up LetterGrid and WordFinder
	string inputStr;
	WordFinder glossary = WordFinder("Glossary.txt");
	glossary.SelectionSortWords(); // Sort Glossary
	cout << "Enter grid file name and extension (ex: input15.txt): ";
	cin >> inputStr;
	LetterGrid wsearch = LetterGrid(inputStr);
	// Print letter grid
	wsearch.PrintGrid();
	cout << "\n";
	// Match and print word search words
	matchWords(glossary, wsearch);
}

int main(){
	wordSearch();
	return 0;
}