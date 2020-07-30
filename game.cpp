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

int game::get_name() {return name;} //getter for name
char * game::get_tag() {return tag;} //getter for tag
bool game::get_win() { return win;} //returns bool

//default constructor
game::game()
{
    tag = NULL;
    win = false;
    name = 0;
}

//parameterized constructor
game::game(int nametoadd)
{
    tag = NULL;
    win = false;
    name = nametoadd;
}

//copy constructor
game::game(game * gtcp)
{
    tag = new char[strlen(gtcp->tag) + 1];
    strcpy(gtcp->tag, tag);
    name = gtcp->name;
    win = gtcp->win;
}

game::~game() //virtual destructor
{
    tag = NULL;
    name = 0;
    win = false;
}

//display function for individual games (not virtual)
int game::display()
{
    if(name)
    {
        std::cout << "Given #: " << name << std::endl;
    }
    if(win)
    {
        std::cout << "win? : " << win << std::endl;
    }
    if(tag)
    {
        std::cout << "tag? : " << tag << std::endl;
    }

    return 1;
}

//virtual default
int game::play()
{
    std::cout << "default game " << std::endl;
    return 1;
}

//virtual quit
void game::quit()
{
}

//virtual taketurn
int game::taketurn()
{
    return 1;
}

//sets tag name of player (virtual)
int game::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}

//copies into the calling class(virtual)
int game::copy(game * gtcp)
{
    tag = new char[strlen(gtcp->tag) + 1];
    strcpy(gtcp->tag, tag);
    win = gtcp->win;
    return 1;
}
///////////////////////////////////////////////////////////////////////

//take turn
int rngGame::taketurn()
{
    std::cout << "turn taken" << std::endl;
    //std::cout << "play again? (y/n)" << std::endl;
    //char choice;
    //std::cin >> choice;
    //std::cin.ignore(100,'\n');
    //if(choice == 'n')
    //{
    //    done = true;
    //}
    return 1;
}

//constructor
rngGame::rngGame()
{
}

//initialization list used here
rngGame::rngGame(int nametoadd): game(nametoadd)
{
}

//destructor
rngGame::~rngGame()
{
}

//play
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
    bool done = false;
    while(done == false)
    {
        std::cout << "Roll? (y/n) No will exit and you will lose. " << std::endl;
        char response;
        std::cin >> response;
        std::cin.ignore(100,'\n');
        int outcome = 0;
        taketurn();
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
            done = false;
            quit();
            return 1;
        }
    }
    return 1;
}

//covers virtual
void rngGame::quit()
{
    std::cout << "quitting RNG" << std::endl;
    //exits the loop
}

//covers virtual
int rngGame::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}

//copies the data members into the calling class.
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

//returns a val between 1-10
int yum::roll()
{
    //rng library pls
    return 5;
}

//init list
yum::yum(int nametoadd):game(nametoadd)
{

}

//default constructor
yum::yum()
{

}

//covers void
int yum::play()
{
    std::cout << std::endl;
    std::cout << "playing matching game yum " << std::endl;

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
        taketurn();
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

//used in play
int yum::taketurn()
{
    std::cout << "turn taken" << std::endl; 
    return 1;
}

//used in play
void yum::quit()
{
    std::cout << "quitting YUM" << std::endl;
}

//destructor
yum::~yum()
{
}

//covers virtual
int yum::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}

//copies args into calling class
int yum::copy(game * gametcp)
{
    name = gametcp->get_name();
    tag = gametcp->get_tag();
    win = gametcp->get_win();
    return 1;
}


/////////////////////////////////////////////////////////

//int list
blackjack::blackjack(int nametoadd): game(nametoadd)
{
}

//default constructor
blackjack::blackjack()
{
}

//default destructor`
blackjack::~blackjack()
{
}

//play
int blackjack::play()
{
    std::cout << std::endl;
    std::cout << "playing blackjack" << std::endl;
    
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
        //int firstcard = roll();
        //int secondcard = roll();
        //int thirdcard = roll();
        int p1 = 0;
        int p2 = 0;
        std::cout << "pick your first card 1,2,3" << std::endl;
        std::cin >> p1;
        std::cin.ignore(100,'\n');
        std::cout << "pick your second card 1, 2, 3" << std::endl;
        std::cin >> p2;
        std::cin.ignore(100,'\n');
        int tally = p1 + p2;
        taketurn();
        std::cout << "player hand :" << tally << std::endl;

        if(tally == 21)
        {
            std::cout << "win" << std::endl;
            win = true;
        }
        else
        {
            std::cout << "lose" << std::endl;
            win = false;
        }
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

//quit
void blackjack::quit()
{
    std::cout <<"quitting blackjack" <<std::endl;
}

//setTag 
int blackjack::setTag(char * name)
{
    tag = new char[strlen(name) + 1];
    strcpy(tag, name);
    return 1;
}

//copy
int blackjack::copy(game * gametcp)
{
    name = gametcp->get_name();
    tag = gametcp->get_tag();
    win = gametcp->get_win();
    return 1;
}

//cover virtual
int blackjack::taketurn()
{
    std::cout << "turn taken" << std::endl;
    return 1;
}
