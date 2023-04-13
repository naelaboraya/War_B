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
    Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,
    Jack,Queen,King//The heighest
    , Ace
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
    int compare_card(Card other);
    std::string toString();


    friend bool operator>(const Card& crd1, const Card& crd2);
    friend bool operator<(const Card& crd1, const Card& crd2);
    friend bool operator==(const Card& crd1, const Card& crd2);
};





#endif
