//this is the implementation for a list of games, it manages a CLL that is comprised of 
//base game nodes (it only serves/works with derived class games)
#include "gameN.h"
#include <cstring>
#include <cstddef>
class gamesL
{
    public:
        gamesL();
        ~gamesL();
        //sumWins();
        //int add(game * newgame);  //how does this handle dynamic binding
        int add(game * newGame); //im pretty sure I don't want this
        int removeAll();
        int display();
        int countwins(); //goes through calls gatherwin and returns the sum
        int play(); //plays game NOT DONE protected:
        int removeAll(gameN * rear);
        int display(gameN * rear);
        int wins; //can we pass it to the 
        gameN * rear; //this is A CLL
};
//this is player.h, .cpp is @ player.cpp
class player : public gamesL
{
    public:
    player();
    ~player();
    player(const player & player_toadd);
    player(char * name); //this will expand as necessary
    int compP(char * name); //returns 0 if match
    int displayP();
    //int createGame(char * choice, game *& newgame); //user decides what derived is created
    //does a thing
    protected:
    char * name;
    //int score; //we coudl just use countwins
};
