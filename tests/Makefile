CC = g++
CPPFLAGS = -std=c++17 -Wall -g

GTEST_DIR = ../googletest

SRC_DIR = ../src

BOX_SOURCES = $(SRC_DIR)/Box.cpp
BOXLIST_SOURCES = $(SRC_DIR)/BoxList.cpp
BOXTREE_SOURCES = $(SRC_DIR)/BoxTree.cpp
PLANTERMGR_SOURCES = $(SRC_DIR)/plantermgr.cpp

TEST_SOURCES = box_tests.cpp boxlist_tests.cpp boxtree_tests.cpp plantermgr_tests.cpp

TEST_TARGET = tests

all: $(TEST_TARGET)

$(TEST_TARGET): $(BOX_SOURCES:.cpp=.o) $(BOXLIST_SOURCES:.cpp=.o) $(BOXTREE_SOURCES:.cpp=.o) $(PLANTERMGR_SOURCES:.cpp=.o) $(TEST_SOURCES:.cpp=.o) $(GTEST_DIR)/build/lib/libgtest.a
	$(CC) $(CPPFLAGS) -o $@ $^ -L$(GTEST_DIR)/build/lib -lgtest -lgtest_main -pthread

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $< -I$(GTEST_DIR)/googletest/include

clean:
	rm -f $(TEST_TARGET) $(SRC_DIR)/*.o *.o

test: $(TEST_TARGET)
	./$(TEST_TARGET)
