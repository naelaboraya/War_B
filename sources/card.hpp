#ifndef CARD_HPP
#define CARD_HPP


#include <iostream>

enum SUIT {//card suits
    Diamonds,
    Spades,
    Clubs,
    Hearts
};

enum NUMBER {//card numbers [A-K]
    Ace,//The lowest
    Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,
    Jack,Queen,King//The heighest
};

class Card{

    private :

    SUIT card_suit;
    NUMBER card_number;  

    public :

    //constructor:
    Card(NUMBER c_number , SUIT c_suit);

    SUIT getCardSuit();

    NUMBER getCardNumber();

    std::string toString();
};





#endif