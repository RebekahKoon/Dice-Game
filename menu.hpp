/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Header file for the menu function that asks the
**               user whether or not they want to run the Dice game.
**               Returns the user's choice. 
**               Adapted from project 1 menu.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "validInput.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::getline;
using std::atoi;
using std::string;
using std::endl;

int menu();

#endif