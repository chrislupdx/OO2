//gamesList.cpp 
//cs202
//chris lu
//this file has the .cpp implentation for both gameslist and players
#include "gamesList.h"
#include "cstddef"
#include <iostream>
#include <cstring>
//default constructor
gamesL::gamesL()
{
    wins = 0;
    rear = NULL; 
}

//default destructor
gamesL::~gamesL()
{
    wins = 0;
    if(rear)
    {
        removeAll();
    }
}

//if the calling class is bigger or equal, return 1
int gamesL::compareWins(gamesL * listtocompare)
{
    if(this->wins >= listtocompare->wins)
    {
        return 1;
    }
    return 0;
}

//sets wins
int gamesL::set_wins(int value)
{
    wins = value;
    return 1;
}

//go through the whole list and sum wins
int gamesL::sumWins()
{
    return sumWins(rear->to_next());
}

//recursively move through gamesList, calling and summing wins per game
int gamesL::sumWins(gameN * rear)
{
    if(this->rear == rear) //might need guards
    {
        return rear->gatherWin();
    }
    return sumWins(rear->to_next()) + rear->gatherWin();
    //put it somehwhere
}

int gamesL::get_wins() 
{ 
    wins = sumWins();
    return wins;
}

//needs to be implemented
int gamesL::removeAll()
{
    return removeAll(rear); 
}

//recursively traverse and delete everything
int gamesL::removeAll(gameN * rear)
{
    if(!rear) return 0;
    if(rear) 
    { 
        gameN * temp = rear->to_next();
        delete rear;
        rear = temp;
    }
    return removeAll(rear);
}

//wrapper function: find matching
int gamesL::delGame(int namenumtodel)
{
    if(!rear)
    {
        std::cout << "empty game list." << std::endl;
        return 0;
    } 
    gameN * curr = rear->to_next();
    gameN * prev = rear; 
    return delGame(namenumtodel, curr, prev); 
}

int gamesL::delGame(int todel, gameN *& rear, gameN *& prev)
{
    if(this->rear == rear && rear->to_next() == rear) 
    {
        int name= rear->get_name();

        if(todel == name) 
        {
            delete this->rear; //do we need this kw
            this->rear = NULL; 
            return 1;
        }
    }

    if(this->rear == rear) //base case
    {
        int name = rear->get_name();
        if(todel == name)
        {
            gameN * temp = rear;
            rear = rear->to_next();
            this->rear = rear;
            prev->to_next() = rear; //attempts to take non-pointer val
            delete temp;
            temp = NULL;
            return 1;
        }
    }
    int name = rear->get_name();
    if(todel == name)  //general case?
    {
        gameN * temp = rear;
        rear = rear->to_next();
        prev->to_next() = rear;
        delete temp; //i don't know if this actually deleting the thing
        temp = NULL;
        return 1;
    }
    delGame(todel, rear->to_next(), prev->to_next()); 
    //node * temp = curr;
    //curr = curr->next();
    //delete temp;
    //previous->next() = curr;
    return 0;
}

//and to rear
int gamesL::add(game * newN)
{
    std::cout << "adding " << std::endl;
    if(!rear) //if empty /base case
    {
        rear = new gameN(newN);  //i think this is using gameN.cpp's upcasting constructor
        rear->to_next() = rear;
        return 0;
    }
    gameN * temp = new gameN(newN);
    gameN * front = rear->to_next();
    rear->to_next() = temp;
    temp->to_next() = front;
    rear = temp;
    return 1;
}

//display wrapper
int gamesL::display()
{
    if(wins)
    {
        std::cout << "Wins :" << wins << std::endl;
    }
    if(!rear)
    {
        std::cout << "empty gamelist" << std::endl;
        return 1;
    }
    std::cout << "displaying games: " << std::endl; 
    display(rear->to_next());
    std::cout << "display end" << std::endl;
    return 0;
}

//recursive display
int gamesL::display(gameN * curr)
{
    if(curr == rear)
    {
        curr->display();
        std::cout << std::endl;
        return 0;
    }
    curr->display();
    return display(curr->to_next());
}

//play the game then move the curr pointer down the list
int gamesL::play()
{
    rear->play();
    rear = rear->to_next(); //rotate to the next game
    return 1;
}

/////////////////////////////////
//default constructor
player::player()
{
    name = NULL; 
}

//paramterized constructor
player::player(char * nametoadd )
{
    name = NULL;
    name = new char[strlen(nametoadd) + 1];
    strcpy(name, nametoadd);
}

//copy constructor
player::player(const player & player_toadd)
{
    if(player_toadd.name)
    {
    name = new char[strlen(player_toadd.name) + 1];
    strcpy(name, player_toadd.name);
    }
    else
    {
    name = NULL; 
    }
}

//default destructor
player::~player()
{
    name = NULL; 
}

//display
int player::displayPlayername()
{
    if(name)
    {    
        std::cout << "Player " << name << std::endl;
        if(wins)//i wonder if score should be moved to the base class call
        {
        std::cout << "Score : " << wins << std::endl;
        }
    }
    else
    {
        std::cout << "no name" << std::endl;
    }

    return 1;
}

//compare
int player::compP(char * nametocp)
{
    if(strcmp(name, nametocp) == 0)
    {
    return 0;
    }
    return 1;
}

//default constructor
gameN::gameN()
{
    next = NULL;
}

//copy constructor
gameN::gameN(game * gameToadd) 
{
    rngGame * r_test = dynamic_cast<rngGame*>(gameToadd);
    if(r_test) 
    {
        aGame = new rngGame; //set the node's game to game type rng
        aGame->copy(gameToadd);  //thoughts on a dynamically bound copy 
    }
    yum * y_test = dynamic_cast<yum*>(gameToadd);
    if(y_test)
    {
        aGame = new yum;
        aGame->copy(gameToadd);
    }
    blackjack *b_test = dynamic_cast<blackjack*>(gameToadd);
    if(b_test)
    {
        aGame = new blackjack;
        aGame->copy(gameToadd);
    }
    next = NULL;
}

//i hope to god this copy constructor works with dynamic binding
gameN::gameN(gameN * nodetcp)
{
    next = NULL; 
    //aGame = new game(nodetcp->r_game());// ugh this getter doesn't work
}

//default destructor
gameN::~gameN()
{
    next = NULL;
    aGame = NULL;
}

//bool->int conversion of wins
int gameN::gatherWin()
{
  if(aGame->get_win() == true)
  {
    return 1; //literally counting ones
  }
  return 0;
}

//calls play
int gameN::play()
{
    return aGame->play();
}


//calls display 
int gameN::display()
{
    if(aGame)
    {
    return aGame->display();
    }
    return 0;
}

int gameN::get_name() {return aGame->get_name();}
gameN *& gameN::to_next() {return next; }// changed back to *&
