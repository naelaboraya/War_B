
#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include <random>


//constructor: 
Game::Game(Player p1 , Player p2):player1(p1),player2(p2){
    //  this->player1 = p1;
    //  this->player2 = p2;
    this->print_single_turn = "";
    this->init_game();
}


//destructor:
Game::~Game(){}


//functions:
void Game::init_game(){
    this->deck();
    this->shuffle();
    this->give_cards();
}


void Game::shuffle(){
   std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->Deck.begin(), this->Deck.end(), g);

   // random_shuffle(this->Deck.begin(), this->Deck.end());
}

void Game::deck(){
    for (int i = 0; i < 52; i++) {
     Card c(static_cast<NUMBER>(i % 13), static_cast<SUIT>(i / 13));
     this->Deck.push_back(c);
    }
}

void Game::give_cards(){
    for (size_t i = 0; i < 26; i++) {
        this->player1.add_card_to_stack(this->Deck[i]);
        this->player2.add_card_to_stack(this->Deck[i + 26]);
    }
}

void Game::addTotable(Card c){
    this->table.push_back(c);
}

void Game::war(Card c1 , Card c2){

    cout << "war!!" << endl;

    Card c1_down = this->player1.Takefirstcard();
    Card c2_down = this->player2.Takefirstcard();
    Card c1_up = this->player1.Takefirstcard();
    Card c2_up = this->player2.Takefirstcard();

    
    

    if (c1_up.compare_card(c2_up) == 1) {
        // Player 1 wins the war
        this->player1.add_card_to_cards_taken(c1);
        this->player1.add_card_to_cards_taken(c2);
        this->player1.add_card_to_cards_taken(c1_down);
        this->player1.add_card_to_cards_taken(c2_down);
        this->player1.add_card_to_cards_taken(c1_up);
        this->player1.add_card_to_cards_taken(c2_up);
        
    }
      else if (c1_up.compare_card(c2_up) == 2) {
        // Player 2 wins the war
        this->player2.add_card_to_cards_taken(c2);
        this->player2.add_card_to_cards_taken(c1);
        this->player2.add_card_to_cards_taken(c2_down);
        this->player2.add_card_to_cards_taken(c1_down);
        this->player2.add_card_to_cards_taken(c2_up);
        this->player2.add_card_to_cards_taken(c1_up);
        
    }   
    else {
        // draw
        this->addTotable(c1_down);
        this->addTotable(c1_up);
        this->addTotable(c2_down);
        this->addTotable(c2_up);
        war(c1_up, c2_up);
        
    }
}


void Game::playTurn(){

    if (this->is_finished()){
        throw std::logic_error("Game Over");
    }
    
    Card c1 = this->player1.Takefirstcard();
    Card c2 = this->player2.Takefirstcard();
    this->print_single_turn =this->player1.getName()+" played "+c1.toString()+" "+this->player2.getName()+" played "+c2.toString();
    //cout << print_single_turn << endl; 
    int cmp_cards = c1.compare_card(c2);

    if(cmp_cards == 1){//c1 is greater
        this->player1.add_card_to_cards_taken(c1);
        this->player1.add_card_to_cards_taken(c2);
        this->print_single_turn += ". "+ this->player1.getName() + " wins.";
        cout << print_single_turn << endl; 
    }
    else if(cmp_cards == 2){
        this->player2.add_card_to_cards_taken(c2);
        this->player2.add_card_to_cards_taken(c1);
        this->print_single_turn += ". "+ this->player2.getName() + " wins";
        cout << print_single_turn << endl; 
    }
    else { // cmp_cards == 0 (2 cards are equal) -> War!!
        // std::cout << "war!!" << endl;

        war(c1,c2);
        //playTurn();
    }

    
}

void Game::printLastTurn(){

}

void Game::playAll(){

}

void Game::printWiner(){

}

void Game::printLog(){

}

void Game::printStats(){

}

bool Game::is_finished(){
    if (this->player1.stacksize()== 0 && this->player2.stacksize() == 0){
        return true;
    }
    return false;
}



std::string Game::game_toString(){
    std::string info = "";
    info += "Players: " + player1.getName() + " vs. " + player2.getName() + "\n";
    info += "player 1 stack size = : " + std::to_string(player1.stacksize()) +"\n";
    info += "player 2 stack size = : " + std::to_string(player2.stacksize()) +"\n";
    info += "Deck: \n";
    for(Card card : this->Deck){
        info += card.toString() + "\n";
    }
    info += "\n";
    info += "Player 1 hand: \n";
    for(Card card : *player1.getStack()){
        info += card.toString() + "\n";
    }
    info += "\n";
    info += "Player 2 hand: \n";
    for(Card card : *player2.getStack()){
        info += card.toString() + "\n";
    }
    return info;
}



//--------------------------------------------------------------------------------

// void Game::reset(){
//     this->player1.getStack()->erase(this->player1.getStack()->begin());
// }





