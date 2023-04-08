#ifndef GAME_HPP
#define GAME_HPP



namespace ariel {
    
}



class Game {

private:

Player player1,player2;//the game's players
std::vector<Card> Deck;//all the 52 cards that will be divided to 2 players
std::vector<Card> table;//holds the temporary cards in case of war
std::string print_single_turn;
std::string print_all_turns;
int game_over;
std::string winner;
//bool is_finished;



//private functions:

void deck();//inits the deck with all 52 cards
void shuffle();//shuffles the deck cards
void give_cards();//gives each player 26 card from the suffled deck
bool is_finished();//true iff the game is over

public:
//constructor:
Game(Player p1, Player p2);


//destructor:
~Game();

Player getplayer1(){
    return this->player1;
}

Player getplayer2(){
    return this->player2;
}

std::string getWinner(){
    return this->winner;
}

void setWinner(){
    if(!this->is_finished()){
        this->winner = "there is no winner yet!";
    }
    if(this->player1.cardesTaken() > this->player2.cardesTaken()){
        this->winner = "the winner is : " + this->player1.getName();
        std::cout << this->winner << endl;
    }
    else if (this->player2.cardesTaken() > this->player1.cardesTaken()){
        this->winner = "the winner is : " + this->player2.getName();
        std::cout << this->winner << endl;
    }
    else {
        throw logic_error("The game ended with draw");
    }
}

//functions:
void playTurn();
void printLastTurn();
void playAll();
void printWiner();
void printLog();
void printStats();

void init_game();

std::string game_toString();

void addTotable(Card c);//adds to the table the face up/down cards in case of war
void war(Card c1 , Card c2);
//void reset();

};


#endif