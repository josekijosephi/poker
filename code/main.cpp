
#include "cards.h"
#include "player.h"
#include "ring.h"
#include "game_master.h"

#define NUM_GAMES 10
#define TERMINAL 0
#define C_L_ARGS 3

int main(int argc, char** argv)
{

    Game_Master master;

    std::vector<Player> players;
    players.push_back(Player("Viktor Vaughn", 100));
    players.push_back(Player("King Geedorah", 100));
    players.push_back(Player("MF DOOM", 100));
    players.push_back(Player("Danger Doom", 100));

    Ring my_game(players);

    master.play_round(&my_game, std::stoi(argv[1]), std::stoi(argv[2]));

    return 0;
}
