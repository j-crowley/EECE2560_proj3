GCC = g++
CFLAGS = -g -O3 -Wall
OBJS = main.o LetterGrid.o WordFinder.o

search: $(OBJS)
	$(GCC) $(OBJS) -o search

main.o: main.cpp LetterGrid.h WordFinder.h d_matrix-1.h sort_algorithms.h
	$(GCC) $(CFLAGS) -c main.cpp

LetterGrid.o: LetterGrid.cpp LetterGrid.h
	$(GCC) $(CFLAGS) -c LetterGrid.cpp

WordFinder.o: WordFinder.cpp WordFinder.h LetterGrid.h d_matrix-1.h sort_algorithms.h
	$(GCC) $(CFLAGS) -c WordFinder.cpp

clean:
	rm -f $(OBJS) search
