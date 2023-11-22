CXX = clang++
CXXFLAGS = -std=c++17
CC = clang
CCFLAGS = -std=c17

all: dnumll

dnumll: dnumll.cpp
	$(CXX) $(CXXFLAGS) -o dnumll dnumll.cpp

clean:
	rm -rf dnumll dnumll_debug
