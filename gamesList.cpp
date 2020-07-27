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


//and to rear
int gamesL::add(game * newN)
{
    //super boring cll insertion algorithmn
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
