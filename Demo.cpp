/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main() {
  // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2); 
   //for (int i=0;i<5;i++) {
    // game.playTurn();
   //}
   //game.printLastTurn(); // print the last turn stats. For example:
                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
   std::cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
   std::cout << p1.cardesTaken() << endl;
   std::cout << p2.cardesTaken() << endl; // prints the amount of cards this player has won. 
   game.playAll();
   std::cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
   std::cout << p1.cardesTaken() << endl;
   std::cout << p2.cardesTaken() << endl; //playes the game untill the end
   game.printWiner(); // prints the name of the winning player
   game.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
   game.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
  // for (Card c : *p1.get_stack_of_cards_taken()){
  //   cout << "++--" + c.toString() +"++--" << endl;
  // }
  // cout << "------------------------------" << endl;
  // for (Card c : *p2.get_stack_of_cards_taken()){
  //   cout << "++--" + c.toString() +"++--" << endl;
  // }
  Player p3("nael");
  Player p4("nader");
  Game g3(p3,p4);
  //cout << g3.game_toString() << endl;
  
  //cout << cards_won << endl;
  // Card c2(Eight , Hearts);
  // p3.add_card_to_cards_taken(c2);
  // int cards_won = p3.cardesTaken();
  // Card cc = p3.get_stack_of_cards_taken()->front();
  // cout << cc.toString() << endl;

  // for (int i=0 ; i<26 ; i++){
  //   Card c1 = p3.Takefirstcard();
  //   cout << c1.toString() << endl;
  //   cout << p3.stacksize() << endl;
  // }
  
  // cout << p3.playertoSting() << endl;
  // cout << "\n" << endl;
  // cout << p4.playertoSting() << endl;

  
  // cout << "\n" << endl;
  // cout << p3.playertoSting() << endl;
  // cout << "\n" << endl;
  // cout << p4.playertoSting() << endl;
  
    Player p6("a");
    Player p7("b");
    Game ggg(p6, p7);
    int maxTurns = 26;
    
    // for (int i = 0 ; i <= 26 ; i++ && p1.stacksize()>=0)
    // {
    //     game.playTurn();
    // }
    Player p8("Alice");
    Player p9("Bob");
    Game ggame(p1, p2);
    ggame.playAll();
    cout << p8.stacksize() << endl;
    cout << p9.stacksize() << endl;
    ggame.playTurn();
    ggame.playTurn();
    ggame.printLastTurn();
}

  

