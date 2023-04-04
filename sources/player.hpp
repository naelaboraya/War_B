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
    std::vector<Card> stack;//the cards stack that the player has 
    int num_of_cards_taken;



    public:
    //constructor:
    Player(std::string player_name);


    //functions:
    int stacksize();
    int cardesTaken();

    
    
};





#endif