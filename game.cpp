//this is the implementation of game.cpp
#include "game.h"
#include <cstddef>
#include <cstring>
#include <iostream>

/*
 * Game Class: line 8
 * rngGame Class: line 55
 * 2game Class:  line 124
 */
game::game()
{
    tag = NULL;
    win = false;
}

game::game(game * gtcp)
{
    tag = new char[strlen(gtcp->tag) + 1];
    strcpy(gtcp->tag, tag);
    win = gtcp->win;
}

game::~game()
{
    tag = NULL;
    win = false;
}

int game::display()
{
    //displaying order in list would bedope but uncessary
    std::cout << "game # " << std::endl;
    std::cout << "win? : " << win << std::endl;
    if(tag)
    {
    std::cout << "tag? : " << tag << std::endl;
    }
    return 1;
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

//copies into the calling class
int game::copy(game * gtcp)
{
    tag = new char[strlen(gtcp->tag) + 1];
    strcpy(gtcp->tag, tag);
    win = gtcp->win;
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
    std::cout << std::endl;
    std::cout << "playing RNGGame" << std::endl;

    char name[20];
    
    std::cout << "input name " << std::endl;
    std::cin >> name;
    std::cin.ignore(100,'\n');
    setTag(name);
    std::cout << "tag is : " << tag << std::endl;


    std::cout << "Roll? (y/n) No will exit and you will lose. " << std::endl;
    char response;
    std::cin >> response;
    std::cin.ignore(100,'\n');
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
            quit();
    return 1;
}

int rngGame::quit()
{
    std::cout << "quitting RNG" << std::endl;
    //exits the loop
    return 1;
}

int rngGame::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}

//copies the data members into the arg.
int rngGame::copy(game * gametcp)
{
    //call the base function's copy
    return 1;
}

//returns a random value between 1-10
int rngGame::rollDie() //i think we need to do rtti style dynamic casting for this non-virtual
{
    return 5;
    //returns the value
}

/////////////////////////////////////////////////////////////////////////////////

yum::yum()
{

}

yum::~yum()
{

}
