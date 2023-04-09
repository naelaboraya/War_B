
#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include <random>


//constructor: 
// Game::Game(Player p1 , Player p2):player1(p1),player2(p2){
//     //  this->player1 = p1;
//     //  this->player2 = p2;
//     this->print_single_turn = "";
//     this->print_all_turns = "";
//     this->winner = "";
//     this->game_over = 0;
//     this->init_game();
// }
Game::Game(Player p1, Player p2)
    : player1(std::move(p1)), player2(std::move(p2)),
      print_single_turn(""), print_all_turns(""), winner(""), game_over(0)
{
    init_game();
}



//destructor:
// Game::~Game(){

// }


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

    //cout << "war!!" << endl;
    if (this->player1.stacksize()>=2 && this->player1.stacksize()>=2){
    Card c1_down = this->player1.Takefirstcard();
    Card c2_down = this->player2.Takefirstcard();
    Card c1_up = this->player1.Takefirstcard();
    Card c2_up = this->player2.Takefirstcard();
    this->print_single_turn =this->player1.getName()+" played "+c1_up.toString()+" "+this->player2.getName()+" played "+c2_up.toString();
    
    
    

    if (c1_up.compare_card(c2_up) == 1) {
        // Player 1 wins the war
        this->player1.add_card_to_cards_taken(c1);
        this->player1.add_card_to_cards_taken(c2);
        this->player1.add_card_to_cards_taken(c1_down);
        this->player1.add_card_to_cards_taken(c2_down);
        this->player1.add_card_to_cards_taken(c1_up);
        this->player1.add_card_to_cards_taken(c2_up);
        this->print_single_turn += ". "+ this->player1.getName() + " wins.";
        this->print_all_turns += print_single_turn +"\n";
        
    }
      else if (c1_up.compare_card(c2_up) == 2) {
        // Player 2 wins the war
        this->player2.add_card_to_cards_taken(c2);
        this->player2.add_card_to_cards_taken(c1);
        this->player2.add_card_to_cards_taken(c2_down);
        this->player2.add_card_to_cards_taken(c1_down);
        this->player2.add_card_to_cards_taken(c2_up);
        this->player2.add_card_to_cards_taken(c1_up);
        this->print_single_turn += ". "+ this->player2.getName() + " wins.";
        this->print_all_turns += print_single_turn +"\n";
        
    }   
    else {
        // draw
        this->addTotable(c1_down);
        this->addTotable(c1_up);
        this->addTotable(c2_down);
        this->addTotable(c2_up);
        this->print_single_turn += ". Draw.";
        this->print_all_turns += print_single_turn +"\n";
        war(c1_up, c2_up);
        
    }
 }
    else if (this->player1.stacksize()<2 && this->player1.stacksize()<2){
         if(this->player1 . stacksize() == 1 && this->player2.stacksize() == 1){
            this->player1.add_card_to_cards_taken (this->player1.getStack()->front());
            this->player2.add_card_to_cards_taken (this->player2.getStack()->front());
         }
         else if (this->player1 . stacksize() == 0 && this->player2.stacksize() == 0)   
         return;
     }
     
}


void Game::playTurn(){

    if(this->game_over == 1){
        throw std::logic_error("Game Over");
    }

    if (this->player1.getName() == this->player2.getName()) {//same players -> throw exception
    throw std::logic_error("The same player!!!");
    }

    
    if(this->player1.stacksize() > 0 && this->player2.stacksize() >0){
    Card c1 = this->player1.Takefirstcard();
    Card c2 = this->player2.Takefirstcard();
    this->print_single_turn =this->player1.getName()+" played "+c1.toString()+" "+this->player2.getName()+" played "+c2.toString();
    //cout << print_single_turn << endl; 
    int cmp_cards = c1.compare_card(c2);

    if(cmp_cards == 1){//c1 is greater
        this->player1.add_card_to_cards_taken(c1);
        this->player1.add_card_to_cards_taken(c2);
        this->print_single_turn += ". "+ this->player1.getName() + " wins.";
        this->print_all_turns += print_single_turn +"\n";
        //cout << print_single_turn << endl; 
    }
    else if(cmp_cards == 2){
        this->player2.add_card_to_cards_taken(c2);
        this->player2.add_card_to_cards_taken(c1);
        this->print_single_turn += ". "+ this->player2.getName() + " wins";
        this->print_all_turns += this->print_single_turn +"\n";
        //cout << print_single_turn << endl; 
    }
    else { // cmp_cards == 0 (2 cards are equal) -> War!!
        // std::cout << "war!!" << endl;
        this->print_single_turn += ". Draw.";
        this->print_all_turns += print_single_turn +"\n";
        war(c1,c2);
        //playTurn();
    }
    }

    
}

void Game::printLastTurn(){
    std::cout << this->print_single_turn << endl; 
}

void Game::playAll(){
    while(!this->is_finished()){
        this->playTurn();
    }
    this->game_over = 1;
}

void Game::printWiner(){
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

void Game::printLog(){
    std::cout << this->print_all_turns << endl; 
}

void Game::printStats(){

}

bool Game::is_finished(){
    if ((this->player1.stacksize()== 0 && this->player2.stacksize() == 0) || (this->game_over == 1)){
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





