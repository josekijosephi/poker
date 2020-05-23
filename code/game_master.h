#ifndef GAME_MASTER_H
#define GAME_MASTER_H

#include "action.h"
#include "player.h"
#include "ring.h"
#include "hands.h"

class Game_Master
{
    private:
        // Going to see whether we need to have the game as an attribute
        int rounds_played;
        int show_down_time; // 0 unless it's time for the show down

        Action get_actions(Ring* ring, Player p);
        void execute_action(Ring* ring, Player* p, Action action);
        // Execute action is happy if it can exe one of the following
        // folds if the player tries something illegal
        //
        // With this layout we can use function pointers to reduce code
        // duplication
        void fold_player(Ring* ring, Player* p, double size);
        void money_moves(Ring* ring, Player* p, double size);
        Player choose_winner(Ring* ring, std::vector<Player>* players);

    public:
        // We either init a vector of players
        // or a full game
        Game_Master() { rounds_played = 0; }

        void play_round(Ring* ring, int num_rounds, int term); // This should do everything for the round

        int get_rounds_played() { return rounds_played; }
        void add_player_to_ring(Ring* ring, Player player) { ring->add_player(player); }
        void increase_round_count(int num) { rounds_played = rounds_played + num; }
};

int find_player_position(Ring *ring, std::string name);

#endif
