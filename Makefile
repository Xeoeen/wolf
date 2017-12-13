FLAGS = -std=c++1z -Wall -Wextra -I .

live:
	$(CXX) $(FLAGS) live.cpp -o live.bin
test: tests/*.cpp wolf/*.hpp
	$(CXX) $(FLAGS) tests/*.cpp -o test
