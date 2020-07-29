#include "sys.h"
#include <iostream>
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

//overloaded version takes a char
int sys::retrievePlayer(char * player_name)
{
    return retrievePlayer(head, player_name);    
}

//goes thorugh the actual list
int sys::retrievePlayer(playerN * head, char * name_tf)
{
    if(!head) return 0;

    if(head->compare(name_tf) == 0)
    {
        head->displayN();
    }
    return retrievePlayer(head->to_next(), name_tf);
}

//creates a game, and passes it to the recursive call
int sys::addGame(char * player_name, int option, int nam)
{
    if(option == 1)
    {
        game * rng = new rngGame(nam); //why can't I do this here?
        return addGame(head, player_name, rng);
    }
    if(option == 2)
    {
        game * y = new yum(nam);
        return addGame(head, player_name, y);
    }
    if(option == 3)
    {
        game * bj = new blackjack(nam);
        return addGame(head, player_name, bj);  //chef's kiss i am so proud of this function
    }
    return 1;
}

//find the right player and add it
int sys::addGame(playerN * head, char * name_tf, game *& gameta)
{
    if(!head) return 0;

    if(head->compare(name_tf) == 0)
    {
        head->addGame(gameta);
    }
    return addGame(head->to_next(), name_tf, gameta);
}

int sys::deletePlayer(char * player_name)
{
    return deletePlayer(head, player_name);
}

//recursively traverse then delete
int sys::deletePlayer(playerN *& head, char * player_name)
{
    if(!head) return 0;
    if(head->compare(player_name) == 0)
    {
        playerN * temp = head->to_next();
        delete head;
        head = temp; //successful deletion
        //if(!head) return 0; //if we wanted find and delete all matching cases
        return 0;
    }
    return deletePlayer(head->to_next(), player_name);
}
