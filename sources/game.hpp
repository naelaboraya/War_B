#ifndef GAME_HPP
#define GAME_HPP

#include "card.hpp"
#include "player.hpp"


namespace ariel {
    
}



class Game {

private:

Player& player1;//the game's players
Player& player2;
std::vector<Card> Deck;//all the 52 cards that will be divided to 2 players
std::vector<Card> table;//holds the temporary cards in case of war
std::string print_single_turn;
std::string print_all_turns;
int game_over;//0 if no 1 if yes 
std::string winner;




//private functions:

void deck();//inits the deck with all 52 cards
void shuffle();//shuffles the deck cards
void give_cards();//gives each player 26 card from the suffled deck


public:
//constructor:
Game(Player& pl1, Player& pl2);



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

void addTotable(Card crd);//adds to the table the face up/down cards in case of war
void war(Card crd1 , Card crd2);

bool is_finished();//true iff the game is over
std::string game_toString();

};


#endif
