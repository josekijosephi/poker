/*
 * In here we need to make funky 
 * actions for each players...
 *
 */

#include <vector>
#include <string>
#include <iostream>

#include "action.h"
#include "ring.h"

// Two simple player init
Player::Player()
{
    // This is the basic empty player name = "";
    chip_count = 0;
}

Player::Player(std::string n, double chips)
{
    name = n;
    chip_count = chips;
}

void Player::print_player(int method)
{
    std::cout << "Player Name: " << name << std::endl;
    std::cout << "Chip Count:  " << chip_count << std::endl;
    std::cout << "Status:      " << status << std::endl;
    std::cout << "With the following cards:" << std::endl;
    
    pretty_card_print(pocket_cards);

}

Action Player::choose_action(double bet)
{
    /* 
     * This is - well it will be - the thicc bitch:
     *  here we need to read the game and pick a move
     *  it will be executed in two steps..
     *      (1) Simply do the bare minimum - check and call
     *      (2) make some thicc decisions
     */

    Action action;

    if (bet - curr_in_pot == 0) // the bet minus what we have contributed so far
        action.check();
    else // Just call and continue
        action.call(bet - curr_in_pot);

    return action;
}
