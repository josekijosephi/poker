/* 
 * This serves as the game runner...
 * game_master will be in control of going through
 * each round of action, moving money around and 
 * choosing the winner at the showdown.
 */

#include <vector>
#include <iostream>
#include <string>

#include "game_master.h"
#include "action.h"
#include "player.h"
#include "ring.h"
#include "hands.h"

void Game_Master::fold_player(Ring* ring, Player* p, double size)
{
    if (size != 0)
        std::cout << "folding player wants to bet?" << std::endl;
    for (int i = 0; i < 2; i++)
        p->pop_pocket_card();

    p->set_status(2); // game symbol for folded
    ring->set_live_players(ring->get_live_players() - 1);
}
void Game_Master::money_moves(Ring* ring, Player* p, double size)
{
    if (p->get_chip_count() < size)
    {
        std::cout << "Player want's to bet more than they possess - going all in.\n";
        ring->add_to_pot(p->get_chip_count());
        if (p->get_chip_count() > ring->get_bet_size())
            ring->set_bet_size(p->get_chip_count());
        p->set_chip_count(0);
        p->set_status(-1);
        p->set_curr_in_pot(p->get_chip_count());
    } else // The player is good for it
    {
        // This works for calls, bets and raises + checks
        ring->add_to_pot(size);
        if (size >  ring->get_bet_size())
            ring->set_bet_size(size);
        p->reduce_chip_count(size);
        p->set_status(1);
        p->set_curr_in_pot(size);
    }
}

void Game_Master::execute_action(Ring* ring, Player* p, Action action)
{

    if (action.get_action() == fo)
        fold_player(ring, p, action.get_bet());
    else
        money_moves(ring, p, action.get_bet());
    // having issues compiling this fp shit
    //void (Game_Master::*)action_function (Ring*, Player*, double);
    //action_function = (action.get_action() == fo) ? &Game_Master::fold_player : &Game_Master::money_moves;

    //action_function(ring, &p, action.get_bet());
}

Action Game_Master::get_actions(Ring* ring, Player p)
{
    return p.choose_action(ring->get_bet_size());
}

// This goes around and resets curr in pot
void reset_players_curr_in_pot(Ring* ring)
{
    for (int i = 0; i < ring->num_live_players(); i++)
        ring->get_player(i)->set_curr_in_pot(0);
    
}
int find_player_position(Ring *ring, std::string name)
{
    for (int i = 0; i < ring->get_players_at_table()->size(); i++)
        if (!name.compare(ring->get_player(i)->get_name()))
            return i;
    return 0;
}


int player_Hand_sorting(Player a, Player b)
{
    // This can become it's own function
    return Hand_order(a.get_player_hand(), b.get_player_hand());
}

Player Game_Master::choose_winner(Ring* ring, std::vector<Player>* players)
{


    std::vector<Card> base_cards(*ring->get_community_cards());
    
    // The first thing we need to do is calculate the value of each player's hand
    for (auto it = players->begin(); it != players->end(); ++it)
    {
        std::vector<Card> cards(base_cards);
        std::vector<Card> player_cards = it->get_pocket_cards();

        cards.insert(cards.end(), player_cards.begin(), player_cards.end());

        it->set_player_hand(find_hand(cards));

        player_cards.clear();
    }

    base_cards.clear();

    // We need to get the value of every hand
    std::vector<Player> finding_winner(*ring->get_players_at_table());

    // sort players based off their hand value
    std::sort(finding_winner.begin(), finding_winner.end(), player_Hand_sorting);


    //
    // But this is a pointer to that mem so it's all good
    return finding_winner.front();
}

