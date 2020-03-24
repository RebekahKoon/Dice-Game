/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Source file for LoadedDie class, which inherits from
**               the Die class. Contains constructor that initializes
**               N in the Die class. Also contains virtual member
**               function rollDie to roll a die that favors the die's
**               greatest side number and overrides rollDie in the
**               Die class.
*********************************************************************/

#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include "Die.hpp"

#include <string>
#include <cstdlib>

using std::string;

class LoadedDie: public Die
{
    public:
        LoadedDie(int sidesIn);
        virtual int rollDie();
};

#endif