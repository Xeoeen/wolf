FLAGS = -std=c++1z -Wall -Wextra -I .

live:
	$(CXX) $(FLAGS) live.cpp -o live.bin
testRunner: tests/main.cpp tests/*.hpp wolf/*.hpp
	$(CXX) $(FLAGS) tests/main.cpp -o testRunner
