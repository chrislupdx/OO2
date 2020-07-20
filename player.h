//this is hte implementation for the player.h
#include <cstddef>
#include <cstring>

class player 
{
    public:
    player();
    ~player();
    player(char * name); //this will expand as necessary

    int copyP(player * player_tocopy); //copies arg into the calling class
    int displayP();

    protected:
    char * name;
    //game * gameList; //A CLL?
};
