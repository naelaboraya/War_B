#include "player.hpp"




//constructors :

Player::Player(std::string player_name): stack{},stack_of_cards_taken{}{
   this->name = player_name; 
   this->num_of_cards_taken = 0;
}



//functions :

void Player::add_card_to_stack(Card crd){
    this->stack.push_back(crd);
}

void Player::add_card_to_cards_taken(Card crd){
     std::cout << "Adding card " << crd.toString() << " to player " << name << "'s stack\n";
    this->stack_of_cards_taken.push_back(crd);
}

int Player::stacksize(){
    return this->stack.size();
}
int Player::cardesTaken(){
    return this->stack_of_cards_taken.size();
}

Card Player::Takefirstcard(){
    if(this->stacksize() == 0){
        throw std::logic_error("player has no cards");
    }
    Card res = this->stack.front();
    this->stack.erase(this->stack.begin());
    return res;
}

std::string Player::playertoSting(){
    std::string info = "";
    info += "name : " + this->name;
    info += "\n";
    info += "stack size = " + std::to_string(this->stacksize());
    info += "\n";
    info += "cards taken = " + std::to_string(this->cardesTaken());

    return info; 
}

void Player::reset(){
    this->stack.clear();
    this->stack_of_cards_taken.clear();
    num_of_cards_taken = 0;
}
