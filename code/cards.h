#ifndef CARDS_H
#define CARDS_H

#include <vector>
#include <string>

#define NUM_SUITS 4
#define NUM_VALUES 13
#define NUM_CARDS 52

enum Suit { 
    Clubs=0, // utf encoding: \u2667
    Diamonds, // utf encoding: \u2662
    Spades, // utf encoding: \u2664
    Hearts // utf encoding: \u2661

};
enum Value {
    Two=0,
    Three,
    Four, 
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card
{
    private:
        Suit suit;
        Value value;
        std::string symbol; // This should have the unicode
        char number; // Letter to represent the card
    public:
        Card(Suit s, Value v);
        void print_card(int method);
        Suit get_suit() { return suit; }
        Value get_value() { return value; }
        std::string get_symbol() { return symbol; }
        char get_number() { return number; }
};

class Deck
{
    private:
        std::vector<Card> cards;
        void push_card(Card card) { cards.push_back(card); } // Only want us to be able to add cards
    public:
        Deck(); // This is this initializer method to fill a new deck of cards
        void print_deck(int method);
        int num_cards() { return cards.size(); }
        Card pop_card();
        void clear_cards() { cards.empty(); }
};

void pretty_card_print(std::vector<Card> cards);
void simple_card_print(std::vector<Card> cards, std::vector<Card> pocket);
#endif
