# Makefile for CPS 1160 by Gladys Monagan

.PHONY: all check run test clean remove

VERSION = -std=c++17

CXX = g++

#DEBUG  = -g

CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DEBUG)

LFLAGS = $(VERSION) $(DEBUG)

INC = linkedlist.h

SRC = linkedlist
# SRC = linkedlist_rec

UNITTEST = dtest_ll

TEST_PROG = test_linkedlist

all : $(UNITTEST)

check : all
	./$(UNITTEST)

run : all
	$(UNITTEST).exe

test : $(TEST_PROG)

$(SRC).o : $(SRC).cpp $(INC)
	$(CXX) $(CFLAGS) -c $(SRC).cpp

$(UNITTEST).o : $(UNITTEST).cpp $(INC)
	$(CXX) $(CFLAGS) -c $(UNITTEST).cpp

$(UNITTEST) : $(SRC).o $(UNITTEST).o
	$(CXX) $(LFLAGS) $(CFLAGS) $^ -o $@

$(TEST_PROG).o : $(TEST_PROG).cpp $(INC)
	$(CXX) $(CFLAGS) -c $(TEST_PROG).cpp

$(TEST_PROG): $(SRC).o $(TEST_PROG).o
	$(CXX) $(LFLAGS) $^ -o $@

# for Windows
clean:
	del $(UNITTEST).exe $(TEST_PROG).exe *.o  /Q
	@echo clean done

# for UNIX / Linux 
remove:
	rm -f $(UNITTEST) $(TEST_PROG) *.o
	@echo clean done

# copyright 2022 Gladys Monagan

