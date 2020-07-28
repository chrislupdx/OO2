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
        int gatherWin(); //NOT DONE
        int play(); //NOT DONE
        //sumWins(); //NOT DONE
        int display(gameN * rear);
       
    protected:
        int delGame(int todel, gameN *& rear, gameN *& prev);
        
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
        int displayP();
        //int createGame(char * choice, game *& newgame);
    protected:
        char * name;
};
