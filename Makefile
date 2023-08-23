CC = g++
CPPFLAGS = -std=c++17 -Wall -g

planters: planters.o Box.o BoxList.o BoxTree.o plantermgr.o

planters.o: planters.cpp

plantermgr.o: plantermgr.cpp plantermgr.h

Box.o: Box.cpp Box.h

BoxList.o: BoxList.cpp BoxList.h

BoxTree.o: BoxTree.cpp BoxTree.h

clean:
	rm *.o planters