/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Header file for the Game class. The Game class has
**               functions to find the number of rounds to be played 
**               in the dice game and the type/number of sides for 
**               each die. createDice creates either an unloaded or
**               loaded die for each player. playGame function rolls 
**               the dice using the Die class if the die is unloaded
**               or LoadedDie class if loaded and prints who won each
**               round. printGameResults prints who won the game.
*********************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include "validInput.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "menu.hpp"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

//Used to determine whether die should be unloaded or loaded
enum DieType {UNLOADED_DIE = 1, LOADED_DIE = 2};

class Game
{
    private:
        //Pointers to Die objects for both players
        Die *player2;
        Die *player1;

        //Tracking whether players are using unloaded/loaded die
        int dieTypeP1;
        int dieTypeP2;

        int dieSidesP1;
        int dieSidesP2;

        int setRounds();
        void setDieType();
        void setSideNumber();

        //Using the Die/LoadedDie classes to create Die
        void createDie();

        //Printing the winner
        void printGameResults(int, int);

    public:
        Game();
        void playGame();
};

#endif