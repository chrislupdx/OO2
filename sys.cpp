#include "sys.h"
#include <iostream>

sys::sys()
{
    head = NULL; 
}

//init list for sy

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

//recursively inserts a player into a LLL
int sys::insertPlayerN(player player_toadd, playerN *& head)
{
    if(!head)
    {
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
int sys::createPlayer(player player_toadd)
{
    insertPlayerN(player_toadd, head);

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
    std::cout << "displaying " << std::endl;
    displayPlayers(head);
    return 1;
}
