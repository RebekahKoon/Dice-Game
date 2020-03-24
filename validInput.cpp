/**********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Source file for functions validInput, which takes in
**               two integers representing the minimum and maximum
**               values that can be entered. Determines if user input
**               is valid and returns the user's input as an integer.
**               Adapted from my project 1 validInput function.
**********************************************************************/

#include "validInput.hpp"


/***********************************************************************
** Description: Function validInput takes two integers representing the
**              the range an integer should be in as parameters. User
**              will enter a string. Makes user reenter input until a 
**              correct response is entered. If the string is an integer
**              and within the desired range, converts to an integer and
**              returns the integer. 
***********************************************************************/
int validInput(int minNumber, int maxNumber)
{
    bool valid;
    int numberInt;
    string answer;

    //Performs until a valid input is entered
    do
    {
        getline(cin, answer);
        valid = true;

        //Checking to see if the string is a positive integer
        for (int i = 0; i < answer.length(); i++)
        {
            if (!isdigit(answer[i]))
            {
                valid = false;
            } 
        }

        //Check to see if integer is within correct range
        if (valid)
        {
            //Convert to an integer to check if it is within the min/max range
            numberInt = atoi(answer.c_str());

            //Checking to see if the integer is between the min/max range
            if (numberInt < minNumber || numberInt > maxNumber)
            {
                valid = false;
            }
        }

        //If input was not a correct choice
        if (!valid)
        {
            cout << "Please only type integers from "
                 << minNumber << " to " << maxNumber << ": ";
        }
    } while (valid == false);

    return numberInt;
}