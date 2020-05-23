/*
 * This is a file dedicated to the Game_Master::Play_Round function
 *
 * It is getting too cluttered having it at the bottom of game_master.cpp
 *
 */
#include <thread>
#include <chrono>

#include "game_master.h"



void reset_live_player_status(Ring* ring);
int all_players_acted (Ring *ring);


void Game_Master::play_round(Ring* ring, int max_rounds, int terminal_output)
{
    std::string winning_hands[] = {"Straight Flush", "Four of a Kind", "Full House", 
        "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair", "High Card"};

    // Array of function pointers for a while loop
    void (Ring::*deal_functions[])(Deck*) = { 
        &Ring::deal_cards, &Ring::flop, &Ring::turn, &Ring::river 
    };

    while (ring->is_winner() && rounds_played < max_rounds)
    {
        Deck fresh_cards;

        if (rounds_played % 5 == 4)
            ring->double_blinds();
        // Removal of broke player, clearing cards, blinds
        ring->prepare_round();
        
        if (ring->num_live_players() == 1)
            // Only one player left so it's time to bounce
            break;

        int curr_players = ring->num_players();

        // Now proceed with dealing and wheeling
        for (auto loop_fn : deal_functions)
        {
            ring->card_fn = loop_fn;
            // Deal the cards then get on with business
            //  -> this will loop through all different card playings
            (ring->*(ring->card_fn))(&fresh_cards);

            // traverser keep going around the table until all players have acted
            int traverser = 0;
            while (!all_players_acted(ring))
            {
                // Here we go around the table taking bets
                if (ring->get_player(traverser % curr_players)->get_status() == 0)
                {
                    Action act = ring->get_player(traverser % curr_players)->choose_action(ring->get_bet_size());


                    if (act.get_action() == be)
                        reset_live_player_status(ring);

                    execute_action(ring, ring->get_player(traverser % curr_players), act);
                }

                traverser++;
            }

        }

        //ring->print_summary();

        // Now we need to pick the winner from this shit
        Player winner = choose_winner(ring, ring->get_players_at_table());

        if (terminal_output)
            std::cout << winner.get_name() << " won with a " << 
                winning_hands[winner.get_player_hand().get_hand()] << std::endl;
        else
            std::cout << "Winner," << winner.get_name() << ",Hand," << 
                winning_hands[winner.get_player_hand().get_hand()] <<std::endl;

        int pos = find_player_position(ring, winner.get_name());
        ring->take_from_pot(ring->get_player(pos));

        if (terminal_output)
        {
            pretty_card_print(winner.get_pocket_cards());
            pretty_card_print(*ring->get_community_cards());
        } else
            simple_card_print(winner.get_pocket_cards(), *ring->get_community_cards());

        std::cout << "\n\n";


        ring->clear_all_cards();
        ring->reset_pot_size();
        ring->remove_broke_players();
        rounds_played++;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}


// This is going to return 1 if there is a player at the table who hasn't 
// played in the hand yet
int all_players_acted (Ring *ring)
{
    for (auto it : *ring->get_players_at_table())
        if (it.get_status() == 0)
            return 0;
    // if we make it this far then everyone has acted
    return 1;
}

void reset_live_player_status(Ring* ring)
{
    for (auto it = ring->get_players_at_table()->begin(); 
            it != ring->get_players_at_table()->end(); ++it)
        // If the player has acted, then reset to non-act-ed
        if (it->get_status() == 1)
            it->set_status(0);
}
