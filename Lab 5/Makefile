# Bikram Kohli (11658)

CXX=clang++ $(CXXFLGS)
CXXFLGS=-Wall -O2
DEBUG=-g

a.out: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX) $(DEBUG) AVLNode.o AVLTree.o AVLPathTest.o

AVLNode.o: AVLNode.cpp AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out
