//game.h
//This should be virtual
class game
{
    public:
    //parameteriazed constructor ?
    game();
    game(game * gtcp); //do we need to virtualize this in some way
    game(int nametoadd);
    virtual ~game();
    virtual int play()=0; //pure virtual, can only make pointers via dynamic binding
    virtual void quit()=0;
    virtual int taketurn(bool & done)=0;
    virtual int setTag(char * name)=0;
    virtual int copy(game * gametcp)=0; //i think this needs to exist 
    int display(); //ugh god can we even call this
   
    int get_name();
    char * get_tag();
    bool get_win(); //converts win to a number
    //int quit();//exit the loop + return data member
    
    //if(we need overloaded operators) implement here
    //derived_type * new_ptr = <dynamic_cast><derived_type *> (old_ptr);
    //getWinData();
    protected: int name;
    char * tag;
    bool win; //convert to int
};

class rngGame : public game
{
    public:
        rngGame();
        rngGame(int nametoadd);
        ~rngGame(); //but that's not an identical signature...does this work?
        //parameterized constructor 
        
        int play(); //can invoke quit/rollDie/setTag
        void quit(); //exit the loop + return data bember:
        int taketurn(bool & done);
        int setTag(char * name);
        //int static_cast<type*>pickCard();
        int rollDie();
        int copy(game * gametcp);
private:
};

//id second game rules
class yum : public game
{
    public:
        yum();
        yum(int nametoadd);
        ~yum();
        
        int taketurn(bool & done);
        int play(); //NOT DONE 
        void quit();
        int setTag(char * name); //not done
        int roll();
        int copy(game * gametcp); //not done
    private:
};

//id third game rules
class blackjack : public game
{
    //each draw two numbres
    //whoever has the bigger pile wins
    public:
        blackjack();
        blackjack(int nametoadd);
        ~blackjack();
        int play(); //not done
        void quit(); //not done
        int setTag(char * name); //not done
        int copy(game * gametcp); //not done
        int taketurn(bool & done);

    private:
};
