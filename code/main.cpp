#include "cards.h"
#include "player.h"
#include "ring.h"
#include "game_master.h"

#define NUM_GAMES 10
#define TERMINAL 0
#define C_L_ARGS 3

int main(int argc, char** argv)
{

    std::string names[] = {
        "Viktor Vaughn","King Geedorah","MF DOOM", "Danger Doom",
        "Czarface","Madvillain","Metro Boomin", "Saint-Laurent Don",
        "Playboi Carti","Shéyaa Bin Abraham-Joseph"
    };

    // begin by making the players around the ring
    std::vector<Player> players;

    if (argc == 4)
    {
        // then the user has passed in the arguments at command line
        Game_Master master;

        for (int i = 0; i < std::stoi(argv[1]); i++)
            players.push_back(Player(names[i], 100));

        Ring my_game(players);
        master.play_round(&my_game, std::stoi(argv[2]), std::stoi(argv[3]));
    } else
    {
        // We have to assume all info is coming through stdin

        int num_players;
        std::cin >> num_players;

        for (int i = 0; i < num_players; i++)
            players.push_back(Player(names[i], 100));

        int num_games, terminal_output;

        while (std::cin >> num_games && std::cin >> terminal_output)
        {
            // for some reason I need to create a new game_master object
            // or else main isn't happy playing multiple rounds
            Game_Master master;

            Ring my_game(players);
            master.play_round(&my_game, num_games, terminal_output);
            std::cout << "done ?" <<std::endl;
        }
    }

    return 0;
}
