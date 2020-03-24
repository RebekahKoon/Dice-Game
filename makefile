## Program name: lab3
## Author:       Rebekah Koon
## Date:         7/9/19
## Description:  Makefile that compiles a program that plays a dice game
##               where the player who rolls the highest number on a die
##               wins the round and whoever wins the most rounds wins
##               the game.

lab3: Die.o LoadedDie.o Game.o menu.o validInput.o main.o
	g++ -g Die.o LoadedDie.o Game.o menu.o validInput.o main.o -o lab3

Die.o: Die.cpp Die.hpp
	g++ -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -c LoadedDie.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

validInput.o: validInput.cpp validInput.hpp
	g++ -c validInput.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o lab3