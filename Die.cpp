/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Implementation file for the Die class, which is used 
**               to roll a die. Contains a constructor to initialize 
**               the number of sides a die has and a virtual function
**               rollDie to roll the die. Also contains a member 
**               function to return the type of die used.
*********************************************************************/

#include "Die.hpp"


/*********************************************************************
** Description: Constructor for the Die class, which takes an integer
**              as a parameter representing the number of sides a die 
**              has. Uses to initialize number of sides N. Also sets
**              up a seed used to randomly generate the side rolled by 
**              the die. Source: Gaddis et al., section 3.10
*********************************************************************/
Die::Die(int sidesIn)
{
    N = sidesIn;

    type = "unloaded";
    
    //Used to generate random integer for side when die is rolled
    unsigned seed = time(0);
    srand(seed);
}


/*********************************************************************
** Description: Die class member rollDie is a virtual function that 
**              randomly generates a side number when the die is 
**              rolled. Returns the side number rolled.
*********************************************************************/
int Die::rollDie()
{
    int sideRolled;

    //Randomly finding the side rolled
    sideRolled = rand() % N + 1;

    return sideRolled;
}


/*********************************************************************
** Description: Void member function getSides returns N, which is the
**              number of sides on the die.
*********************************************************************/
int Die::getSides()
{
    return N;
}


/*********************************************************************
** Description: Void member function getType returns the type that the
**              die is (either loaded or unloaded).
*********************************************************************/
string Die::getDieType()
{
    return type;
}