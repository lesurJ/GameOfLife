CC = g++
FLAGS = -Wall -g

main : main.o game_logic.o
	$(CC) $(FLAGS) -o main main.o game_logic.o

main.o : main.cpp game_logic.hpp 
	$(CC) $(FLAGS) -c main.cpp

game_logic.o : game_logic.hpp

clean:
	@echo " *** CLEANING *** "
	@/bin/rm -f *.o *.x *.c~ *.h~ *.h.gch
