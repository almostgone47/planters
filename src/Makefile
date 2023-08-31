CC = g++
CPPFLAGS = -std=c++17 -Wall -g

planters: planters.o Box.o BoxList.o BoxTree.o plantermgr.o

planters.o: planters.cpp

plantermgr.o: plantermgr.cpp ../include/plantermgr.h

Box.o: Box.cpp ../include/Box.h

BoxList.o: BoxList.cpp ../include/BoxList.h

BoxTree.o: BoxTree.cpp ../include/BoxTree.h

clean:
	rm *.o planters


