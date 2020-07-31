//cs202
//chris lu
//program 2
//gameslist.h
//this is the implemtation of the CLL of games. note the is a relationship
//#include "gameN.h"
#include <cstring>
#include <cstddef>
#include "game.h"

class gameN
{
    public:
        gameN(); //default constructor
        gameN(game * gametoadd); //RTTI shennanigans
        gameN(gameN * nodetcp);  //copy constructor
        ~gameN(); //default constructor

        int play(); //where is this used
        int display(); //calls the display playerdat member display function
        int gatherWin(); //returns wins as integers
        int get_name(); //gets name (names == numbers in this project)
        gameN *& to_next(); //gets next

    protected:
        int delGame(int * todel, gameN *& rear); //recursive call
        gameN * next; //the next pointer
        game * aGame; //each gameN houses one instance of a game
};

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
    int has_wins(); //return 1 if win > 0
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


