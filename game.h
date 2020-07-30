//game.h
//This should be virtual
class game
{
    public:
    game(); //default
    game(game * gtcp); //copy
    game(int nametoadd); //paramaterized
    virtual ~game(); //virtual destructor
    virtual int play()=0; //virtual, can only make pointers via dynamic binding
    virtual void quit()=0; //virtual
    virtual int taketurn()=0;//virtual
    virtual int setTag(char * name)=0; //virtual
    virtual int copy(game * gametcp)=0; //virtual
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
        rngGame(); //default
        rngGame(int nametoadd); /
        ~rngGame(); //but that's not an identical signature...does this work?
        //parameterized constructor 
        
        int play(); //covers virtual
        void quit(); //used in play
        int taketurn(); //used in play
        int setTag(char * name); //used in play
        int rollDie();  //returns a random number between 1-10
        int copy(game * gametcp); //copies arg into calling class
private:
};

//id second game rules
class yum : public game
{
    public:
        yum();
        yum(int nametoadd);
        ~yum();
        
        int taketurn();
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
        int taketurn();

    private:
};
