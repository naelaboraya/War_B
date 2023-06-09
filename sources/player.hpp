#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "card.hpp"
using namespace std;

class Player{
    private: 
    
    
    std::string name;
    int num_of_cards_taken;
    std::vector<Card> stack;//the cards stack that the player has 
    std::vector<Card> stack_of_cards_taken;
    int num_of_turns_won;


    public:

    int getNum_of_turns_won() const{
    	return this->num_of_turns_won;
    }
    
    void increment_num_of_turns_won(){
    	this->num_of_turns_won++;
    }
    
    //constructor:
    Player(std::string player_name);

   
     
    

    
    //functions:

    

    std::string getName(){
        return this->name;
    }

    std::vector<Card> getStack(){
        return this->stack;
    }   

    std::vector<Card> get_stack_of_cards_taken(){
        return this->stack_of_cards_taken;
    }   
    
    void add_card_to_stack(Card crd);
    void add_card_to_cards_taken(Card crd);
    int stacksize();
    int cardesTaken();
    Card Takefirstcard();
    std::string playertoSting();
    void reset();
    
    
};





#endif
