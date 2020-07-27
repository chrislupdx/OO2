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
    std::cout << "Roll? (y/n) No will exit and you will lose. " << std::endl;
    char response;
    std::cin >> response;
    int outcome = 0;
    if(response == 'y')
    {
        outcome = rollDie();
    }
    else
    {
        std::cout << "you lose " << std::endl;
        win = false;
        //quit(); //wrtie quit
    }
    std::cout << "you rolled : " << outcome << std::endl;
    
    //use take turn?
    if(outcome > 6) //wint if you roll 7+
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
    //std::cout << "quit? (y/n)" << std::endl;
    //char q;
    //std::cin >> q;
    //std::cin.ignore(100, '\n');
    //    if(q == 'y')
    //    {
            std::cout << "quitting" << std::endl;
            //quit();
    //    }
    //    else
    //    {
    //        //continue looping
    //    }

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
int rngGame::rollDie() //i think we need to do rtti style dynamic casting for this non-virtual
{
    return 5;
    //returns the value
}
