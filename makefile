CC = g++
FLAGS = -Wall -g -std=c++11

main : main.o game_logic.o
	$(CC) $(FLAGS) main.o game_logic.o -o main 

main.o : main.cpp game_logic.hpp
	$(CC) $(FLAGS) -c main.cpp

game_logic.o : game_logic.cpp game_logic.hpp
	$(CC) $(FLAGS) -c game_logic.cpp

clean:
	@echo " *** CLEANING *** "
	@/bin/rm -f *.o *.x *.c~ *.h~ *.h.gch
