/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Source file for the menu function, which asks the
**               user whether or not they want to run the dice game.
**               Returns the user's choice. 
*********************************************************************/

#include "menu.hpp"


/*********************************************************************
** Description: Function menu give the option to start the war game
**              with dice or quit. Returns 1 if the game will be 
**              played or 2 if the game will not be played.
**              Adapted from my Project 1 menu.
*********************************************************************/
int menu()
{
    string choiceStr;
    bool validChoice;
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 2;

    cout << "Do you want to play a dice-rolling war game?" << endl;
    cout << "1. Play the Game" << endl;
    cout << "2. Quit" << endl << endl;
    cout << "Please enter either 1 or 2 to perform your choice: ";

    //Calling validInput to see if the user entered 1 or 2
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    return choice;
}