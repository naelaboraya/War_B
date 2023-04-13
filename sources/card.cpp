#include "card.hpp"

Card::Card(NUMBER c_number , SUIT c_suit){
    this->card_number = c_number;
    this->card_suit = c_suit;
}

NUMBER Card::getCardNumber(){
    return this->card_number;
}

SUIT Card::getCardSuit(){
    return this->card_suit;
}

bool operator>(const Card& crd1, const Card& crd2) {
    return static_cast<int>(crd1.card_number) > static_cast<int>(crd2.card_number);
}

bool operator<(const Card& crd1, const Card& crd2) {
    return static_cast<int>(crd1.card_number) < static_cast<int>(crd2.card_number);
}

 bool operator==(const Card& crd1, const Card& crd2) {
    return static_cast<int>(crd1.card_number) == static_cast<int>(crd2.card_number);
}

int Card::compare_card(Card other){//returns 0 if equal , 1 if c1 is greater , 2 if c2 is greater
    if (this->card_number == Ace && other.card_number == Two){
        return 2;
    }
    else if (this->card_number == Two && other.card_number == Ace){
        return 1;
    }
    else if (this->card_number > other.card_number){
        return 1;
    }
    else if (this->card_number < other.card_number){
        return 2;
    }
    else {
        return 0;
    }
}

std::string Card::toString(){

    std::string suit_to_string;
    std::string number_to_string;

    switch(this->card_number){
        case NUMBER::Ace:
            number_to_string = "Ace";
            break;
        case NUMBER::Two:
            number_to_string = "2";
            break;
        case NUMBER::Three:
            number_to_string = "3";
            break;    
        case NUMBER::Four:
            number_to_string = "4";
            break;
        case NUMBER::Five:
            number_to_string = "5";
            break;
        case NUMBER::Six:
            number_to_string = "6";
            break; 
        case NUMBER::Seven:
            number_to_string = "7";
            break;
        case NUMBER::Eight:
            number_to_string = "8";
            break;
        case NUMBER::Nine:
            number_to_string = "9";
            break;   
        case NUMBER::Ten:
            number_to_string = "10";
            break;
        case NUMBER::Jack:
            number_to_string = "Jack";
            break;
        case NUMBER::Queen:
            number_to_string = "Queen";
            break;  
        case NUMBER::King:
            number_to_string = "King";
            break;             
    }
    
    switch(this->card_suit){
        case SUIT::Diamonds:
            suit_to_string = "Diamonds";
            break;
        case SUIT::Hearts:
            suit_to_string = "Hearts";
            break;
        case SUIT::Clubs:
            suit_to_string = "Clubs";
            break;
        case SUIT::Spades:
            suit_to_string = "Spades";
            break;            
    }

    std::string card_to_string = number_to_string + " of " + suit_to_string;
    return card_to_string;
}
