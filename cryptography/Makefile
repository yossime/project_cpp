CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -Werror -Wconversion -g -Wextra
CXXFLAGS+= -std=c++17



check: main
	./main


main: main.o get_mess.o send.o manager.o cryptography.o

cryptography.o:cryptography.cpp cryptography.hpp
manager.o:manager.cpp manager.hpp cryptography.hpp send.hpp get_mess.hpp
send.o:send.cpp send.hpp
get_mess.o: get_mess.cpp get_mess.hpp

main.o: main.cpp manager.hpp


info:
	@echo "function templates demo"
	@echo "may the force be with you!"

clean:
	@echo "cleaning up"
	@rm -rf main.o *.o main *.txt
	