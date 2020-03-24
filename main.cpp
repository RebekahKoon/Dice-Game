/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  This program plays a dice game in which two players
**               roll their respective die for a selected number of
**               rounds. Whoever rolls the larger number wins that
**               round and gains a point, and whoever has the highest
**               score wins. Uses the Game class to input the number 
**               of rounds, if the players are using unloaded or 
**               loaded die, and the number of sides for each die in 
**               order to play the game. The Die and LoadedDie classes 
**               are used in the Game class to roll the players' dice.
**               The Game class then prints who won each round as well
**               as who won the game.
*********************************************************************/

#include "Game.hpp"

int main()
{
    Game warGame;
    
    //Starts the game
    warGame.playGame();

    return 0;
}