#ifndef RING_H
#define RING_H

#include <vector>

#include "cards.h"
#include "player.h"

#define MAX_PLAYERS 10

/* 
 * This should cover everything from the persepctive of 
 * the house: only focused on keeping the game running
 *
 * In another file we worry about taking, and then executing
 * the actions of each player.
 */

class Ring
{
    private:
        std::vector<Player> players;
        std::vector<Card> community_cards;
        std::vector<Card> burnt_cards;
        int max_players = MAX_PLAYERS; // No question
        int live_players; // This starts as the total table then reduces to 1
        double pot_size;
        double bet_size;
        double big_blind; // Serves as minimum bet as well

        void take_blinds();
        void reshuffle_positions(); // The D becomes BB

    public:
        Ring (std::vector<Player> p)
        {
            players = p;
            big_blind = 0;
        }

        void (Ring::*card_fn)(Deck*); // this the function pointer
        void print_summary();
        void remove_broke_players();
        void clear_all_cards();
        void reset_pot_size() { pot_size = 0; }
        void prepare_round(); // removes broke players and reshuffles positions
        void deal_cards(Deck* cards); // Will go around giving two cards to each player
        void flop(Deck* cards);
        void turn(Deck* cards);
        void river(Deck* cards);
        void add_player(Player player);
        std::vector<Player> *get_players_at_table() { return &players; }
        Player* get_player(int i) { return &players[i]; }
        int is_winner(); // return 0 if there is a winner: game over

        void add_to_pot(double size) { pot_size = pot_size + size; }
        void take_from_pot(Player* p) { p->set_chip_count(p->get_chip_count() + pot_size); pot_size = 0; }
        void double_blinds() { big_blind = 2 * big_blind; }
        std::vector<Card> *get_community_cards() { return &community_cards; }
        double get_pot_size() { return pot_size; }
        double get_bet_size() { return bet_size; }
        double get_player_chip_count(int i) { return players[i].get_chip_count(); }
        double get_big_blind() { return big_blind; }
        int get_live_players() { return live_players; }
        void set_live_players(int num) { live_players=num; }
        void set_bet_size(double size) { bet_size = size; }
        int num_players() { return players.size(); }
        int num_live_players() { return live_players; }
};

#endif
