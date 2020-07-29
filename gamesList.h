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
    int sumWins();
    int display(gameN * rear);
    int gatherWins(); //sums+sets wins
    int get_wins(); //for the client
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
    int displayP();  //what does that actually do
        //int createGame(char * choice, game *& newgame);
    protected:
        char * name;
};
