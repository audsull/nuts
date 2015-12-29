#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

//card values 1-13
//card suit 1-4
class Card {
public:
  int value;
  int suit;
  //string toSuit(int);
};

//52 cards
class Deck {
  std::vector<Card> card_deck;
public:
  explicit Deck();
  void printDeck();
  void shuffleDeck();
};

//28 cards
class Board: public Deck {
  Card board[28];
public: 
  void printBoard();
};

//10 cards
class NutDeck: public Deck {
  Card nut_deck[10];
public:
  void drawOne();
};

//14 cards
class Solitaire_Deck: public Deck {
  Card sol_deck[14];
public:
  void drawThree();
};

string toSuit(int suit) {
  switch(suit) {
  case 0 : return "hearts";
  case 1 : return "diamonds";
  case 2 : return "spades";
  case 3 : return "clubs";
  default : return "";
  }
}

string toValue(int value) {
  if(value < 11) return std::to_string(value);
  switch(value) {
  case 11 : return "jack";
  case 12 : return "queen";
  case 13 : return "king";
  default : return "";
  }
}

Deck::Deck() {
  Card cur_card;
  for(int i = 1; i <= 13; i++) {
    for(int j = 0; j < 4; j++) {
      cur_card.value = i;
      cur_card.suit = j;
      card_deck.push_back(cur_card);
    }
  }
}

void Deck::printDeck() {
  for(int i = 0; i < 52; i++) {
    cout << toValue(card_deck.at(i).value) << " " << toSuit(card_deck.at(i).suit) << endl;
  }
}

void Deck::shuffleDeck() {
  srand(time(NULL));
  std::random_shuffle(card_deck.begin(), card_deck.end());
}

void burn() {
}

int main() {
  //Build two decks
  Deck team1 = Deck();
  Deck team2 = Deck();

  team1.shuffleDeck();
  team2.shuffleDeck();
  team1.printDeck();
  cout << endl;
  team2.printDeck();

  //Set up the board
  //Nutters and other player build decks
  //play game
  return 0;
}
