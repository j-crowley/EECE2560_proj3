start: main.cpp LetterGrid.cpp WordFinder.cpp
	g++ main.cpp LetterGrid.cpp WordFinder.cpp -o Project3 -std=c++11 -g

clean:
	rm start main.o LetterGrid.o WordFinder.o