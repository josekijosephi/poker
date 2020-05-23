#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

#include "action.h"
#include "cards.h"
#include "hands.h"

class Player
{
    private:
        // I don't know how but we need to include a way to
        // personalize the choices of each player
        std::string name;
        double chip_count;
        std::vector<Card> pocket_cards;
        /* 
         * Meaning of status values:
         * 0 := needs to act,
         * 1 := has acted,
         *-1 := player is all in,
         * 2 := player has folded.
         */
        int status;
        double curr_in_pot; // Need to keep up with how much to contribute
        Hand_Value hand;

    public:
        Player();
        Player(std::string n, double chips);

        Action choose_action(double bet);

        void pop_pocket_card() { pocket_cards.pop_back(); }
        void set_chip_count(double chips) { chip_count = chips; }
        void reduce_chip_count(double chips) { chip_count = chip_count - chips; }
        double get_chip_count() { return chip_count; }
        int get_status() { return status; }
        void set_status(int num) { status = num; }
        std::string get_name() { return name; }
        std::vector<Card> get_pocket_cards() { return pocket_cards; }
        double get_curr_in_pot() { return curr_in_pot; } 
        void set_curr_in_pot(double bet) { curr_in_pot = bet; }
        void set_player_hand(Hand_Value h) { hand = h; }
        Hand_Value get_player_hand() { return hand; }
        void clear_pocket_cards() { if (pocket_cards.size() > 0) pocket_cards.clear(); }


        void print_player(int method);
        void push_card_to_hand(Card card) { pocket_cards.push_back(card); } };

#endif
