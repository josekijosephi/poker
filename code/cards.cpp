/*
 *  Here we are concerned with creating a new deck 
 *  of cards and printing a current deck
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include <chrono> // we are going to try get milliseconds and pump fresh cards out faster
//#include <ctime>

#include <cstdlib>

#include "cards.h"



// These two make assignment easier
std::vector<std::string> suits = { "\u2667", "\u2662", "\u2664", "\u2661" };
std::string values = "23456789TJQKA";

Card::Card(Suit s, Value v)
{
    suit = s;
    value = v;
    symbol = suits[s];
    number = values[v];
}

void Card::print_card(int method)
{
    if ( method == 1 )
    {
        std::cout << "\u2219\u2219\u2219\u2219\u2219" << std::endl;
        std::cout << "\u2219" << std::setw(2) << number << std::setw(4) << "\u2219" << std::endl;
        std::cout << "\u2219" << std::setw(4) << symbol << std::setw(4) << "\u2219" << std::endl;
        std::cout << "\u2219\u2219\u2219\u2219\u2219" << std::endl;
        std::cout << "\n";
    } else
    {
        std::cout << "Suit," << symbol << ",Value," << number << std::endl;
    }
}

Deck::Deck()
{
    // Create a way to check if a card has been used 
    int all_cards[NUM_SUITS][NUM_VALUES];
    for (int i = 0; i < NUM_SUITS; i++)
        for (int j = 0; j <NUM_VALUES; j++)
            all_cards[i][j] = 0;

    int count = 0;

    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            );
    std::srand(ms.count());

    while (++count <= NUM_CARDS)
    {
        int i, j;
        i = std::rand() % NUM_SUITS;
        j = std::rand() % NUM_VALUES;

        int row_cycles = 0, col_cycles = 0;
        while (all_cards[i][j])
        {
            // we need to find the next free card
            j++;
            j = j % NUM_VALUES;
            col_cycles++;
            i = i + (col_cycles % NUM_VALUES == 0);
            i = i % NUM_SUITS;
        }
        all_cards[i][j] = 1;
        cards.push_back(Card((Suit)i,(Value)j));
    }
}

void Deck::print_deck(int method)
{
    // Going to cycle trhough all cards and print them
    // using dogmatic c++
    for (std::vector<Card>::iterator it = cards.begin();
            it != cards.end(); ++it)
        it->print_card(method);
}

Card Deck::pop_card()
{
    // Need to utilise the pop function
    // but return the last card too
    Card last_card = cards.back();
    cards.pop_back();
    return last_card;
}

void pretty_card_print(std::vector<Card> cards)
{
    for (int i = 0; i < cards.size(); i++)
        std::cout << "\u2219\u2219\u2219\u2219\u2219  ";
    std::cout << std::endl;

    for (int i = 0; i < cards.size(); i++)
        std::cout << "\u2219" << std::setw(2) << cards[i].get_number() << std::setw(6) << "\u2219  ";
    std::cout << std::endl;

    for (int i = 0; i < cards.size(); i++)
        printf("%s %s %s  ", "\u2219", cards[i].get_symbol().c_str(),"\u2219");
    std::cout << std::endl;

    for (int i = 0; i < cards.size(); i++)
        std::cout << "\u2219\u2219\u2219\u2219\u2219  ";
    std::cout << std::endl;
}
void simple_card_print(std::vector<Card> pocket, std::vector<Card> cards)
{
    for (auto it : pocket)
            it.print_card(0);
    //for (auto it : cards)
    //        it.print_card(0);
}
