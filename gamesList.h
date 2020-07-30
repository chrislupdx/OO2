#include "gameN.h"
#include <cstring>
#include <cstddef>

class gamesL
{
public:
    gamesL();
    ~gamesL();
    int add(game * newGame);
    int removeAll();
    int display();
    int delGame(int namenumtodel);
    int removeAll(gameN * rear);
    int play(); 
    int display(gameN * rear);
    int compareWins(gamesL * listtocompare); //are we even able to point them to each other
    int sumWins(); //goes through the list and gets all of them
    int get_wins(); //for the client (does it actually grab all of them)
    int set_wins(int value);
protected:
    int delGame(int todel, gameN *& rear, gameN *& prev);
    int sumWins(gameN * rear);
    int wins; //can we pass it to the 
    gameN * rear; //this is A CLL
};

class player : public gamesL
{
public:
    player();
    ~player();
    player(const player & player_toadd);
    player(char * name);
    int compP(char * nametocp);
    int displayPlayername();  //what does that actually do
    protected:
        char * name;
};
