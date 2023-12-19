CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -Werror -Wconversion -g -Wextra
CXXFLAGS+= -std=c++17



check: clean main
	./main


main: matrix.cpp 

main.o: matrix.hpp 


info:
	@echo "function templates demo"
	@echo "may the force be with you!"

clean:
	@echo "cleaning up"
	@rm -rf main.o swap.o main