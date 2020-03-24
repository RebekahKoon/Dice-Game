/**********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Header file for the Die class, which is used to roll
**               a die. Contains a constructor to initialize the number
**               of sides a die has and a virtual function rollDie to
**               roll the die. Also contains a member function to 
**               return the type of die used.
**********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

class Die
{
    private:
        //Number of sides on a die
        int N;

    protected:
        //Used to track the type of the die
        string type;

    public:
        Die(int sidesIn);
        virtual int rollDie();
        int getSides();
        string getDieType();
};

#endif