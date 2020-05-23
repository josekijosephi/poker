
#include <iostream>
#include <vector>

#include "ring.h"
#include "player.h"
#include "cards.h"


// We begin by defining the private functions
int Ring::is_winner()
{
    return (players.size() > 1); // ie if one player then return 0
}

void Ring::remove_broke_players()
{
    // We will double up and reset status count
    // Traverse vector and check chip count
    // if count <= 0 then remove from the table
    std::vector<int> broke;
    for (int index = 0; index < players.size(); index++)
        if (players[index].get_chip_count() <= 0)
            broke.push_back(index);
        else
            players[index].set_status(0);

    // Now start at back and remove broke players
    for (int jndex = broke.size(); jndex > 0; --jndex)
    {
        std::cout << "We say good-bye to " << players.at(broke[jndex-1]).get_name() << std::endl;
        players.erase(players.begin() + broke[jndex-1]);
    }

}
void Ring::take_blinds()
{
    // Take the blinds if they have the chips to do so
    // otherwise they go all-in
    for (int i = 0; i < 2; i++)
    {
        if (players[i].get_chip_count() >= (big_blind / (i+1)))
        {
            players[i].reduce_chip_count(big_blind/(i+1));
            players[i].set_curr_in_pot(big_blind/(i+1));
            add_to_pot(big_blind/(i+1));
        } else
        {
            // This is a broke boi so set status to all in
            players[i].reduce_chip_count(players[i].get_chip_count());
            players[i].set_curr_in_pot(players[i].get_chip_count());
            players[i].set_status(-1); // all in
            add_to_pot(players[i].get_chip_count());
        }
    }
    players[0].set_status(1);
    bet_size = big_blind;
}

void Ring::reshuffle_positions()
{
    // Now we do the switch trick to bump D to BB position
    Player last = players.back();
    players.pop_back(); // Now the last position wiped

    auto it = players.insert(players.begin(), last);
}

// Now onto the public functions
void Ring::print_summary()
{
    std::cout << "Money in the pot: " << pot_size << std::endl;
    if (!community_cards.empty())
    {
        std::cout << "The community cards:" << std::endl;
        pretty_card_print(community_cards);
    }

    std::cout << "We now print the players at the table with a summary of their stats:" << std::endl;
    for (std::vector<Player>::iterator it = players.begin(); 
        it != players.end(); ++it)
    {
        it->print_player(0); 
        std::cout << "\n\n";
    }

}
void Ring::add_player(Player player)
{
    if (players.size() == max_players)
        std::cout << "Can't exceed maximum number of players around the table!!" << std::endl;
    else
        players.push_back(player);
}

void Ring::clear_all_cards()
{
    community_cards.clear();
    for (auto it = players.begin(); it != players.end(); ++it)
        it->clear_pocket_cards();
}
void Ring::prepare_round()
{
    reshuffle_positions();
    clear_all_cards();
    reset_pot_size();
    take_blinds();
    live_players = players.size(); // When we start everyone is in
}

void Ring::deal_cards(Deck* cards)
{
    // Go around the table and serve two pocket cards 
    // to everyone who is at the table
    for (int round = 0; round < 2; round++)
        for (std::vector<Player>::iterator it = players.begin(); 
                it != players.end(); ++it)
            it->push_card_to_hand(cards->pop_card());
}

void Ring::flop(Deck* cards)
{
    // One burner and then three comm cards
    burnt_cards.push_back(cards->pop_card());

    for (int count = 0; count < 3; count++)
        community_cards.push_back(cards->pop_card());
}

// The following two are the same function
// but the different names make it easier to read in gamemaster
void Ring::turn(Deck* cards)
{
    burnt_cards.push_back(cards->pop_card());
    community_cards.push_back(cards->pop_card());
}
void Ring::river(Deck* cards)
{
    burnt_cards.push_back(cards->pop_card());
    community_cards.push_back(cards->pop_card());
}

