CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

all: ex3

ex3: ex3.cpp
	$(CXX) $(CXXFLAGS) -o ex3 ex3.cpp

clean:
	rm -f ex3
