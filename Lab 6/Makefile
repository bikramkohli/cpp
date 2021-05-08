# Bikram Kohil (11658)

CXX=clang++ $(CXXFLGS)
CXXLFGS=-Wall -O2
DEBUG=-g

a.out: wordPuzzle.o hashTable.o timer.o
	$(CXX) $(DEBUG) wordPuzzle.o hashTable.o timer.o

wordpuzzle.o: wordpuzzle.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h
hashtable.o: hashtable.cpp hashTable.h

.PHONY: clean
clean:
	-rm -f *.o a.out
