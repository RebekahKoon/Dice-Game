/*********************************************************************
** Program name: lab3
** Author:       Rebekah Koon
** Date:         7/9/19
** Description:  Implementation file for the Game class, which has
**               functions to find the number of rounds to be played 
**               in the dice game and the type/number of sides for 
**               each die. createDice creates either an unloaded or
**               loaded die for each player. playGame function rolls 
**               the dice using the Die class if the die is unloaded
**               or LoadedDie class if loaded and prints who won each
**               round. printGameResults prints who won the game.
*********************************************************************/

#include "Game.hpp"


/*********************************************************************
** Description: Default constructor for the Game class. Initializes
**              pointers player1 and player2 to null.
*********************************************************************/
Game::Game()
{
    player1 = NULL;
    player2 = NULL;
}


/*********************************************************************
** Description: Void function setRounds is a private member of the 
**              Game class that asks the user how many rounds of the
**              game will be played. After validating input, returns
**              the number of rounds that will be played.
*********************************************************************/
int Game::setRounds()
{
    int roundsIn;
    const int MIN_ROUNDS = 1,
              MAX_ROUNDS = 100000;

    cout << endl << "How many rounds will be played?" << endl;
    cout << "Type an integer from 1 to 100000 for the number of rounds: ";

    //Setting rounds after validating user input
    roundsIn = validInput(MIN_ROUNDS, MAX_ROUNDS);

    return roundsIn;
}


/*********************************************************************
** Description: Void function setDieType is a private member of the
**              Game class that asks the user for the type of die
**              used by each player. Assigns each player's input to 
**              the dieTypeP1 and dieTypeP2 member variables.
*********************************************************************/
void Game::setDieType()
{

    cout << endl << "Is the die for player 1 unloaded or loaded?" << endl;
    cout << "Type 1 for unloaded or 2 for loaded: ";
    
    //Setting die type for player 1 after validating user input
    dieTypeP1 = validInput(UNLOADED_DIE, LOADED_DIE);

    cout << endl << "Is the die for player 2 unloaded or loaded?" << endl;
    cout << "Type 1 for unloaded or 2 for loaded: ";

    //Setting die type for player 2 after validating user input
    dieTypeP2 = validInput(UNLOADED_DIE, LOADED_DIE);
}


/*********************************************************************
** Description: Void function setSideNumber is a private function of 
**              the Game class that asks each player for the number of
**              sides for their own die. Assigns each player's input 
**              to the dieSidesP1 and dieSidesP2 member variables.
*********************************************************************/
void Game::setSideNumber()
{
    const int MIN_NUM_SIDES = 2,
              MAX_NUM_SIDES = 120;

    cout << endl << "How many sides should the die for player 1 have?" << endl;
    cout << "Type in an integer from 2 to 120: ";

    //Setting die sides for player 1 after validating user input
    dieSidesP1 = validInput(MIN_NUM_SIDES, MAX_NUM_SIDES);

    cout << endl << "How many sides should the die for player 2 have?" << endl;
    cout << "Type in an integer from 2 to 120: ";

    //Setting die sides for player 2 after validating user input
    dieSidesP2 = validInput(MIN_NUM_SIDES, MAX_NUM_SIDES);
}


/*********************************************************************
** Description: Void function createDie is a private member of the
**              Game class that dynamically allocates memory either
**              to a Die object or LoadedDie object depending on 
**              whether each player wants an unloaded or loaded die.
**              Source: office hours.
*********************************************************************/
void Game::createDie()
{
    //Using enum to create either Die or LoadedDie object for player 1's die
    if (dieTypeP1 == UNLOADED_DIE)
    {
        player1 = new Die(dieSidesP1);
    }
    else if (dieTypeP1 == LOADED_DIE)
    {
        player1 = new LoadedDie(dieSidesP1);
    }

    //Using enum to create either Die or LoadedDie object for player 2's die
    if (dieTypeP2 == UNLOADED_DIE)
    {
        player2 = new Die(dieSidesP2);
    }
    else if (dieTypeP2 == LOADED_DIE)
    {
        player2 = new LoadedDie(dieSidesP2);
    }
}


/**********************************************************************
** Description: Void function playGame first calls menu function to
**              determine if the player wants to play the game. Calls 
**              member functions to set the rounds and die type/number
**              of sides for each player. Calls createDie to create the
**              die used by each player. Uses function rollDie from 
**              either the Die or LoadedDie class to find the number 
**              rolled by each player after every round. Gives player
**              with the round's higher number one point. Calls
**              printGameResults to determine the winner of the game.
**              Calls menu to ask if the game should be played again.
**********************************************************************/
void Game::playGame()
{
    int rounds,
        choice,
        numRolledP1,
        numRolledP2,
        scoreP1,
        scoreP2;

    //Choosing whether or not to play the game
    choice = menu();

    while (choice == 1)
    {
        scoreP1 = 0;
        scoreP2 = 0;
        
        //Calling functions get information about rounds and player dice
        rounds = setRounds();
        setDieType();
        setSideNumber();
        createDie();

        for (int i = 0; i < rounds; i++)
        {
            //Finding the current round number
            int roundNum = i + 1;

            cout << endl << "Round " << roundNum << endl;

            //Determines what number player 1 rolls; prints results
            numRolledP1 = player1->rollDie();
            cout << "Player 1 rolled " << numRolledP1 << " on a " << dieSidesP1
                 << "-sided " << player1->getDieType() << " die." << endl;

            //Determines what number player 2 rolls; prints results
            numRolledP2 = player2->rollDie();
            cout << "Player 2 rolled " << numRolledP2 << " on a " << dieSidesP2
                 << "-sided " << player2->getDieType() << " die." << endl;

            //Calculates score if player 1 won the round
            if (numRolledP1 > numRolledP2)
            {
                scoreP1++;

                cout << "Player 1 wins round " << roundNum << "!" << endl;
            }

            //Calculates score if player 2 won the round
            else if (numRolledP1 < numRolledP2)
            {
                scoreP2++;

                cout << "Player 2 wins round " << roundNum << "!" << endl;
            }

            //No points awarded on a draw
            else if (numRolledP1 == numRolledP2)
            {
                cout << "Round " << roundNum << " is a draw!" << endl;
            }

            cout << "Current score for player 1: " << scoreP1 << endl;
            cout << "Current score for player 2: " << scoreP2 << endl;
        }

        //Print who won and final score for each player
        printGameResults(scoreP1, scoreP2);

        //Determining if the game will be played again
        cout << endl << "Do you want to play again?" << endl;
        choice = menu();

        delete player1;
        delete player2;
    }

    //Exiting the game
    cout << "Goodbye!" << endl;
}


/*********************************************************************
** Description: Void function printGameResults takes in the scores
**              for both player 1 and player 2 as parameters. Using
**              these scores, determines and prints who won the game
**              and also prints the final score for both players.
*********************************************************************/
void Game::printGameResults(int score1, int score2)
{
    //If player 1 won the game
    if (score1 > score2)
    {
        cout << endl << "Player 1 wins the game!" << endl;
    }

    //If player 2 won the game
    else if (score1 < score2)
    {
        cout << endl << "Player 2 wins the game!" << endl;
    }

    //If the game is a draw
    else if (score1 == score2)
    {
        cout << endl << "The game is a draw!" << endl;
    }

    cout << "Final score: " << endl;
    cout << "Player 1: " << score1 << endl;
    cout << "Player 2: " << score2 << endl;
}