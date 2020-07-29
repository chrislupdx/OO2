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
    if(rear) { gameN * temp = rear->to_next();
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
   gameN * curr = rear->to_next();
   gameN * prev = rear; 
   return delGame(namenumtodel, curr, prev); 
}

//this is a wrapper
//int gamesL::delGame(int todel, gameN *& curr, gameN *& prev)
//{
//    if(this->rear == curr && this->rear == prev) 
//    {
//        int name= curr->get_name();
//        
//        if(todel == name) 
//        {
//        //gameN * temp = curr;
//        //delete temp;
//        delete this->rear;
//        this->rear = NULL;
//        //temp = NULL;
//        return 1;
//        }
//    }
//
//    if(rear == curr) //base case
//    {
//        int name = curr->get_name();
//        if(todel == name)
//        {
//            gameN * temp = curr;
//            curr = curr->to_next();
//            rear = curr;
//            delete temp;
//            temp = NULL;
//            prev->to_next() = curr; //attempts to take non-pointer value
//            return 1;
//        }
//    }
//    int name = curr->get_name();
//    if(todel == name)
//    {
//        gameN * temp = curr;
//        curr = curr->to_next();
//        delete temp; //i don't know if this actually deleting the thing
//        temp = NULL;
//        prev->to_next() = curr;
//        return 1;
//    }
//    //gameN * nextprev = prev->to_next();
//    //gameN * tonext = curr->to_next();
//    delGame(todel, curr->to_next(), prev->to_next()); 
//
//    //node * temp = curr;
//    //curr = curr->next();
//    //delete temp;
//    //previous->next() = curr;
//    return 0;
//}


int gamesL::delGame(int todel, gameN *& rear, gameN *& prev)
{
    if(this->rear == rear && rear->to_next() == rear) 
    {
        int name= rear->get_name();
        
        if(todel == name) 
        {
        delete this->rear; //do we need this kw
        this->rear = NULL; 
        return 1;
        }
    }

    if(this->rear == rear) //base case
    {
        int name = rear->get_name();
        if(todel == name)
        {
            gameN * temp = rear;
            rear = rear->to_next();
            this->rear = rear;
            prev->to_next() = rear; //attempts to take non-pointer val
            delete temp;
            temp = NULL;
            return 1;
        }
    }
    int name = rear->get_name();
    if(todel == name)  //general case?
    {
        gameN * temp = rear;
        rear = rear->to_next();
        prev->to_next() = rear;
        delete temp; //i don't know if this actually deleting the thing
        temp = NULL;
        return 1;
    }
    //gameN * nextprev = prev->to_next();
    //gameN * tonext = curr->to_next();
    delGame(todel, rear->to_next(), prev->to_next()); 

    //node * temp = curr;
    //curr = curr->next();
    //delete temp;
    //previous->next() = curr;
    return 0;
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
        rear->to_next() = rear;
        //rear->set_next(rear); 
        return 0;
    }
    gameN * temp = new gameN(newN);
    gameN * front = rear->to_next();
    rear->to_next() = temp;
    temp->to_next() = front;
    //rear->set_next(temp); //position temp behind rear
    //temp->set_next(front);
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
        std::cout << std::endl;
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
    //is there a curr pointer that gets bumped down the list
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
