//this is the implentation of the  game systems' .h
//cs202
//chris lu
//sys.cpp
#include "sys.h"
#include <iostream>
//default constructor
sys::sys()
{
    head = NULL; 
    sortH = NULL; 
} 

//this is the wrapper
int sys::sortList()
{
    return sortList(sortH, head);
}

//inserts EOL
int sys::insertsortP(playerN * sortedPlayer, playerN *& emptyhead)
{
    if(!emptyhead)  //if empty
    {
        emptyhead = sortedPlayer; 
        emptyhead->to_next() = NULL;
        return 0;
    }

    if(sortedPlayer->compW(emptyhead) == 1)//if sortedplayer >= emptyhead
    {//think about why this works 
        sortedPlayer->to_next() = emptyhead;   //cosider the recursive scope
        emptyhead = sortedPlayer;
        return 0;
    }
    return insertsortP(sortedPlayer, emptyhead->to_next());
}

//takes tocopy and inserts it into empty
int sys::sortList(playerN *& empty, playerN * tocopy) //this recursion needs love
{
    if(!tocopy) return 0; //brought it back lets see
    playerN * temp = tocopy; 
    tocopy = tocopy->to_next(); //move through target list  
    insertsortP(temp, empty); //generates empty (first call)

    return sortList(empty, tocopy);
}

//recursively deallocates all nodes
int sys::removeAll(playerN *& head)
{
    if(!head) return 0;
    removeAll(head->to_next());
    return 1;
}

//updates wins
int sys::updateWins()
{
    if(!head) return 0;
   return updateWins(head);
}

//this one does ALL the players
int sys::updateWins(playerN *& head)
{
    if(!head) return 0;
    //a catch belo1...
   int caught = head->updateWins();
   //set the player's wins to caught
    head->set_wins(caught);
    return updateWins(head->to_next());
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

//finds and deletes, this is a wrapper
int sys::deleteGame(char * name, int option)
{
    return deleteGame(head, name, option);
}

//recursively finds and calls delete
int sys::deleteGame(playerN * head, char * nametf, int option)
{
    if(!head) return 0;
    if(head->compare(nametf) == 0)
    {
        head->deleteGame(option);
    }
    return deleteGame(head->to_next(), nametf, option); 
}

//wrapper
int sys::playGame(char * name)
{
    return playGame(head, name);
}

//finds the player
int sys::playGame(playerN * head, char * name_tf)
{
    if(!head) return 0;

    if(head->compare(name_tf) == 0)
    {
        head->play(); //this function plays the game then r
    }
    return playGame(head->to_next(), name_tf);
}

//EOL recursively inserts a player into a LLL
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
    head->displayplayerstats(); //man i want to virtualize display 
    int count = displayPlayers(head->to_next()) + 1;
    return count;
}

//recursively displays sorted
int sys::displaySorted(playerN *& head)
{
    if(!head) return 0;
    head->displayplayerstats();
    int count = displayPlayers(head->to_next()) + 1;
    return count;
}

//displays sortH
int sys::displaySorted()
{
    displaySorted(sortH);
    return 1;
}

//wrapper, calls recursive display players
int sys::displayPlayers()
{
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
        head->displayplayerstats();
    }
    return retrievePlayer(head->to_next(), name_tf);
}

//creates a game, and passes it to the recursive call
int sys::addGame(char * player_name, int option, int nam)
{
    if(option == 1)
    {
        game * rng = new rngGame(nam);
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
        return addGame(head, player_name, bj);
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

//wrapper calls recursive delete
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
