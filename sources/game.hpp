#ifndef GAME_HPP
#define GAME_HPP



namespace ariel {
    
}

class Game {

private:

Player player1,player2;
Player* Winner;
std::vector<Card> Deck;
bool is_finished;

public:
//constructor:
Game(Player p1, Player p2);




//functions:
void playTurn();
void printLastTurn();
void playAll();
void printWiner();
void printLog();
void printStats();
};


#endif