#include "gameN.h"
#include <cstring>
#include <cstddef>

//cs202
//chris lu
//gameslist.h
//this is the implemtation of the CLL of games. note the is a relationship

class gamesL
{
public:
    gamesL(); //default constructor
    ~gamesL(); //default destructor
    int add(game * newGame); //
    int removeAll(); //deallocates everything
    int display(); //display
    int delGame(int namenumtodel); //wrapper for delete
    int play();  //wrapper function calls play then rotates to the next after played
    int compareWins(gamesL * listtocompare); //are we even able to point them to each other
    int sumWins(); //goes through the list and gets all of them
    int get_wins(); //for the client (does it actually grab all of them)
    int set_wins(int value); //sets wins
protected:
    int display(gameN * rear); //recursive display
    int removeAll(gameN * rear); //recursive call
    int delGame(int todel, gameN *& rear, gameN *& prev);//recursive delete
    int sumWins(gameN * rear); //recursive sum
    int wins; //can we pass it to the 
    gameN * rear; //this is A CLL
};

class player : public gamesL
{
public:
    player(); //default constructor
    ~player(); //default destructor
    player(const player & player_toadd); //copy constructor
    player(char * name); //paramterized constructor
    int compP(char * nametocp);  //compare, returns 0 if match
    int displayPlayername();  //what does that actually do
    protected:
        char * name;
};
