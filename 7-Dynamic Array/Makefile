.PHONY: all clean remove test

CXX = g++
#DEBUG  = -g
VERSION = -std=c++17
CFLAGS = -pedantic -Wall -Wextra $(DEBUG) $(VERSION)
LFLAGS = $(DEBUG) $(VERSION)

SRCS = BigInts
UNITTEST = unittestBigInts
TEST_PROG = testBigInts

all : $(UNITTEST)

test : $(TEST_PROG)

$(SRCS).o : $(SRCS).h $(SRCS).cpp
	$(CXX) $(CFLAGS) -c $(SRCS).cpp

$(UNITTEST).o : $(SRCS).h $(SRCS).cpp $(UNITTEST).cpp
	$(CXX) $(CFLAGS) -c $(UNITTEST).cpp

$(UNITTEST) : $(SRCS).o $(UNITTEST).o
	$(CXX) $(LFLAGS) $^ -o $@

$(TEST_PROG).o : $(SRCS).h $(SRCS).cpp $(TEST_PROG).cpp
	$(CXX) $(CFLAGS) -c $(TEST_PROG).cpp

$(TEST_PROG) : $(SRCS).o $(TEST_PROG).o
	$(CXX) $(LFLAGS) $^ -o $@

# for Windows
clean:
	del *.o  $(UNITTEST).exe $(TEST_PROG).exe
	@echo clean done

# for UNIX / Linux 
remove:
	\rm -f *.o  $(UNITTEST) $(TEST_PROG)
	@echo clean done

# © 2022 Gladys Monagan 
