/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Implementation file for LoadedDie class that inherits 
**               from the Die class. Contains constructor that 
**               initializes N in the Die class. Also contains virtual 
**               member function rollDie to roll a die that favors the 
**               die's greatest side number and overrides rollDie in
**               the Die class.
**               Source: https://www.learncpp.com/cpp-tutorial/114-
**               constructors-and-initialization-of-derived-classes/
*********************************************************************/


#include "LoadedDie.hpp"

/*********************************************************************
** Description: Constructor for the LoadedDie class, which takes the
**              number of sides for a die as a parameter. The Die 
**              class constructor then uses this value to initialize
**              the N member variable in the Die class and also set up
**              a seed used to randomly generate the side rolled by 
**              the die.
*********************************************************************/
LoadedDie::LoadedDie(int sidesIn): Die(sidesIn)
{
    type = "loaded";
}


/*********************************************************************
** Description: Member function rollDie randomly generates an integer
**              from 1 to 100 to see whether it is greater than 25. If
**              it is greater than 25, then returns the largest side 
**              number for the die. If not, randomly generates another
**              side number and returns that side.
**              Source: https://stackoverflow.com/questions/12885356/
**              random-numbers-with-different-probabilities
*********************************************************************/
int LoadedDie::rollDie()
{
    int sideRolled;

    //Finding the number of sides the die has
    int numSides = getSides();

    //The largest side will be rolled if the random number is greater than 25
    if ((rand() % 100 + 1) > 25)
    {
        sideRolled = numSides;
    }

    //Side other than largest will be randomly chosen if not greater than 25
    else
    {
        numSides--;
        
        sideRolled = rand() % numSides + 1;
    }

    return sideRolled;
}