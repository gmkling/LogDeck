#
# Just a basic makefile to test LogDeck
#

# compilers
CC = clang 
CXX = clang++

# flags
CXXFLAGS += -std=c++11 -stdlib=libstdc++ -g -Wall  
 
# files and dependencies
DEPS = Log.h
INCLUDES = -I. -I/usr/include/

# targets
all: LogDeckTest

LogDeckTest: Log.o main.o
	$(CXX) main.o Log.o -o LogDeckTest

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o main.o main.cpp  

LogDeck.o: Log.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o Log.o Log.cpp

print-flags:
	echo CXXFLAGS is $(CXXFLAGS) $(INCLUDES)

clean: 
	rm *.o LogDeckTest a.out
