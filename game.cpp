//this is the implementation of game.cpp
#include "game.h"
#include <cstddef>
#include <cstring>
#include <iostream>

/*
 * Game Class: line 8
 * rngGame Class: line 92
 * 2game Class:  line 188
 */

int game::get_name() {return name;} //name is aterrible name
char * game::get_tag() {return tag;}
bool game::get_win() { return win;}

game::game()
{
    tag = NULL;
    win = false;
    name = 0;
}

game::game(int nametoadd)
{
    tag = NULL;
    win = false;
    name = nametoadd;
}

game::game(game * gtcp)
{
    tag = new char[strlen(gtcp->tag) + 1];
    strcpy(gtcp->tag, tag);
    name = gtcp->name;
    win = gtcp->win;
}

game::~game()
{
    tag = NULL;
    name = 0;
    win = false;
}

int game::display()
{
    //displaying order in list would bedope but uncessary
    std::cout << "Name: " << name << std::endl;
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
void game::quit()
{
}

int game::taketurn(bool & done)
{
    return done;
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

int rngGame::taketurn(bool & done)
{
    std::cout << "play again? (y/n)" << std::endl;
    char choice;
    std::cin >> choice;
    std::cin.ignore(100,'\n');
    if(choice == 'n')
    {
        done = true;
    }
    return 1;
}

rngGame::rngGame()
{
}

rngGame::rngGame(int nametoadd): game(nametoadd)
{
    //name = new char[strlen(nametoadd) + 1];
    //strcpy(nametoadd, name);
}


rngGame::~rngGame()
{
}

//this should cover the pure virtual's play
int rngGame::play()
{
    std::cout << std::endl;
    std::cout << "playing RNGGame" << std::endl;
    bool done = false;
    while(done == false)
    {
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

        taketurn(done);
    }
    quit();
    return 1;
}

//quit doesn't really do anything
void rngGame::quit()
{
    std::cout << "quitting RNG" << std::endl;
    //exits the loop
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
    name = gametcp->get_name();
    tag = gametcp->get_tag();
    win = gametcp->get_win();
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
int yum::roll()
{
    //rng library pls
    return 5;
}


yum::yum(int nametoadd):game(nametoadd)
{

}

yum::yum()
{

}

int yum::play()
{
    std::cout << std::endl;
    std::cout << "playing matching game yum " << std::endl;

    //why does the loop start here
    char name[20];
    std::cout << "input nametag " << std::endl;
    std::cin >> name;
    std::cin.ignore(100,'\n');
    setTag(name);
    std::cout << "tag is : " << tag << std::endl;
    std::cout << std::endl;
    
    bool done5 = true;
    while(done5)
    {
        std::cout << "pick a number between 1-10" << std::endl;
        int housecore = roll();
        int guess = 0;
        std::cin >> guess;
        std::cin.ignore(100,'\n');
        if(guess == housecore)
        {
            std::cout << "win" << std::endl;
            win = true;
        }
        else
        {
            std::cout << "lose" << std::endl;
            win = false;
        }
    //int caatch = taketurn(done5); //this isn't passing right
    std::cout << "play again? (y/n)" << std::endl;
    char choice;
    std::cin >> choice;
    std::cin.ignore(100,'\n');
    if(choice == 'Y' || choice == 'y')
    {
        std::cout << "MOAR" << std::endl;
    }
    else
    {
        done5 = false;
        quit();
        return 1;
    }
    }
    return 1;
}

int yum::taketurn(bool & done)
{
    return 1;
}

//quit doesn't really do anythinglol
void yum::quit()
{
    std::cout << "quitting YUM" << std::endl;
}

yum::~yum()
{
}




int yum::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}

int yum::copy(game * gametcp)
{
    name = gametcp->get_name();
    tag = gametcp->get_tag();
    win = gametcp->get_win();
    return 1;
}


/////////////////////////////////////////////////////////
blackjack::blackjack(int nametoadd): game(nametoadd)
{
}

blackjack::blackjack()
{
}

blackjack::~blackjack()
{
}

int blackjack::play()
{
    return 1;
}

void blackjack::quit()
{
}

int blackjack::setTag(char * name)
{
    return 1;
}

int blackjack::copy(game * gametcp)
{
    name = gametcp->get_name();
    tag = gametcp->get_tag();
    win = gametcp->get_win();
    return 1;
}

int blackjack::taketurn(bool& done)
{
    std::cout << "play again? (y/n)" << std::endl;
    char choice;
    std::cin >> choice;
    std::cin.ignore(100,'\n');
    if(choice == 'n')
    {
        done = true;
    }
    return 1;
}
