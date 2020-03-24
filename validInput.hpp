/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Header file for functions validInput, which takes in
**               two integers representing the minimum and maximum
**               values that can be entered. Determines if user input
**               is valid and returns the user's input as an integer.
**               Adapted from my project 1 validInput function.
*********************************************************************/

#ifndef VALID_INPUT_HPP
#define VALID_INPUT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::transform;

int validInput(int, int);

#endif