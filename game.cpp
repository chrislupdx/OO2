//this is the implementation of game.cpp
#include "game.h"
#include <cstddef>
#include <cstring>
#include <iostream>

/*
 * Game Class: line 8
 * rngGame Class: line 48
 */
game::game()
{
    tag = NULL;
    win = false;
}

game::~game()
{
    tag = NULL;
    win = false;
}

int game::play()
{
    std::cout << "default game " << std::endl;
    return 1;
}

//gets called in play? iddk
int game::quit()
{
    return 1;
}

int game::taketurn()
{
    return 1;
}

//sets tag name of player
int game::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}
///////////////////////////////////////////////////////////////////////
rngGame::rngGame()
{
}

rngGame::~rngGame()
{
}

//this should cover the pure virtual's play
int rngGame::play()
{
    std::cout << "playing RNGGame" << std::endl;

    //take turn?

    int outcome = rollDie();
    if(outcome > 6)         //wint if you roll 7+
    {
        std::cout << "win." << std::endl;
        win = true;
    }
    else
    {
        std::cout << "Lose. " << std::endl;
        win = false;
    }
    //play again?

    //quit();
    return 1;
}

int rngGame::quit()
{
    std::cout << "quitting RNG" << std::endl;
    //move to the next item in the CLL
    //calls to_next();
    return 1;
}

int rngGame::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}

//returns a random value between 1-10
int rngGame::rollDie()
{
    return 5;
    //returns the value
}
