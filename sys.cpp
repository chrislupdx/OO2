#include "sys.h"

sys::sys()
{
    head = NULL; 
}

//recursively deallocates all nodes
int sys::removeAll(playerN *& head)
{
    if(!head) return 0;

    removeAll(head->to_next());

    return 1;
}

//de-allocs the list
int sys::removeAll()
{
    return removeAll(head); 
}

//default destructor
sys::~sys()
{
    removeAll();
}

//recursively insert into a LLL
int sys::insertPlayerN(playerN * player_toadd, playerN *& head)
{
    if(!head)
    {
        //copy functiuon for playerN?:42
        head = new playerN(player_toadd); //get this smoothed out
        head->to_next() = NULL;
    }
    else
    {
       insertPlayerN(player_toadd, head->to_next()); 
    }
    return 1;
}

//dynaimcally creates a player and houses it into a node
int sys::createPlayer(char * name_toadd)
{
    player * newplayer = new player(name_toadd); //this is dynamic is this working
    playerN * newpN = new playerN(newplayer);   //this is also dynamic

    insertPlayerN(newpN, head);

    return 1; 
}

//the recursive call iterates through the LLL, calling each players' display fn
int sys::displayPlayers(playerN *& head)
{
    if(!head) return 0; 
    
    head->displayN(); //man i want to virtualize display 
    int count = displayPlayers(head->to_next()) + 1;
    return count;
}

int sys::displayPlayers()
{
    displayPlayers(head);
    return 1;
}
