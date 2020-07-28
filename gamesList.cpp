//gamesList.cpp
#include "gamesList.h"
#include "cstddef"
#include <iostream>
gamesL::gamesL()
{
    wins = 0;
    rear = NULL; 
}
gamesL::~gamesL()
{
    wins = 0;
    if(rear)
    {
        removeAll();
    }
}

//needs to be implemented
int gamesL::removeAll()
{
    return removeAll(rear); 
}

//recursively traverse and delete everything
int gamesL::removeAll(gameN * rear)
{
    if(!rear) return 0;
    if(rear)
    {
        gameN * temp = rear->to_next();
        delete rear;
        rear = temp;
    }
    return removeAll(rear);
}

//wrapper function: find matching
int gamesL::delGame(int namenumtodel)
{
    if(!rear)
    {
        std::cout << "empty game list." << std::endl;
        return 0;
    } 
   gameN * next = rear->to_next();
    return delGame(namenumtodel, next); 
}

//traverse then delete game
int gamesL::delGame(int todel, gameN *& curr)
{
    if(rear == curr)
    {
        int name = curr->get_name();
        if(todel == name)
        {
            gameN * temp = curr;
            curr = curr->to_next();
            delete temp;
            rear = NULL;
            return 1;
        }
        return 0;
    }
    int name = curr->get_name();
    if(todel == name)
    {
        gameN * temp = curr;
        curr = curr->to_next();
        delete temp;
        rear = NULL;  //what if we did it forcefully
        return 1; //ook you need to tuck the tail here
    }
    
    gameN * next = curr->to_next(); 
    delGame(todel, next);
    
    if(rear == NULL) //does OTW condition ever go off when we need it to?
    {
        rear = curr;
    }
    return 1;
}

int gamesL::gatherWin()
{
    return 1;
}


//and to rear
int gamesL::add(game * newN)
{
    std::cout << "adding " << std::endl;
    if(!rear) //if empty /base case
    {
        rear = new gameN(newN);  //i think this is using gameN.cpp's upcasting constructor
        rear->set_next(rear); 
        return 0;
    }
    gameN * temp = new gameN(newN);
    gameN * front = rear->to_next();
    rear->set_next(temp); //position temp behind rear
    temp->set_next(front);
    rear = temp;
    return 1;
}

int gamesL::display()
{
    if(!rear)
    {
        std::cout << "empty gamelist" << std::endl;
        return 1;
    }
    std::cout << "displaying games: " << std::endl; 
    display(rear->to_next());
    std::cout << "display end" << std::endl;
    return 0;
}

int gamesL::display(gameN * curr)
{
    if(curr == rear)
    {
        curr->display();
        return 0;
    }

    curr->display();

    return display(curr->to_next());
}

//NOT DONE
int gamesL::play()
{
    rear->play();
    //plays the game on the top of the stack
    //how about the other games?
    return 1;

}

//add the node into the  CLL
//int gamesL::add(gameN * newNode)
//{
//    if(!rear)
//    {
//        rear = new gameN(newNode); //find a way to copy the game into this new node
//        rear->to_next = rear;
//    }
//
//    //0->1
//    //1->2
//    //2+
//}
