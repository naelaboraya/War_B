#include "player.hpp"


//constructor
Player::Player(std::string player_name){
    this->name = player_name;
    this->num_of_cards_taken = 0;

}


//functions :

int Player::stacksize(){
    return this->stack.size();
}
int Player::cardesTaken(){
    return this->num_of_cards_taken;
}
