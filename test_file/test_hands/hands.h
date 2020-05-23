#ifndef HANDS_H
#define HANDS_H
/* 
 * This is where we are going to calculate the value of each hand
 *
 * The winning hands are only to be considered at the showdown so
 *  always passing 7 cards through to these functions
 *
 */
#include <string>
#include <iostream>
#include <vector>

#include "cards.h"

enum Hand {
    Straight_Flush=0,
    Four_Kind,
    Full_House,
    Flush,
    Straight,
    Three_Kind,
    Two_Pair,
    One_Pair,
    High_Card
};

class Hand_Value
{
    private:
        Hand hand;
        Value top_value; // So we can distinguish similar hands

    public:
        // This is the only way I can make Hand_Value objects
        Hand_Value() { hand = High_Card; top_value = Two; }
        Hand_Value(Hand h, Value v) { hand = h; top_value = v; }

        Hand get_hand() { return hand; }
        Value get_top_value() { return top_value; }

        void set_hand(Hand h) { hand = h; }
        void set_top_value (Value v) { top_value = v; }
};


Hand_Value find_hand(std::vector<Card> cards);
int Hand_order (Hand_Value a, Hand_Value b);
std::vector<Card> return_winning_hand(std::vector<Card> comm_cards, 
        std::vector<Card> pocket_cards, Hand_Value hand);

#endif
