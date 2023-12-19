CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -Werror -Wconversion -g -Wextra
CXXFLAGS+= -std=c++17



check: clean main
	./main


main: swap.cpp 

main.o: swap.hpp generics.hpp iteratoer.hpp


info:
	@echo "function templates demo"
	@echo "may the force be with you!"

clean:
	@echo "cleaning up"
	@rm -rf main.o swap.o main