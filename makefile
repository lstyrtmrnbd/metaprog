CXX = clang

FLAGS = -Wall -Wextra -Wpedantic -std=c++14

LINK = -lstdc++

all:
	$(CXX) $(FLAGS) -o tests.bin tests.cpp $(LINK) 
