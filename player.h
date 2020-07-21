//this is hte implementation for the player.h
#include <cstddef>
#include <cstring>

class player 
{
    public:
    player();
    ~player();
    player(const player & player_toadd);
    player(char * name); //this will expand as necessary
    int compP(char * name); //returns 0 if match
    int displayP();

    protected:
    char * name;
    //game * gameList; //A CLL?
};
