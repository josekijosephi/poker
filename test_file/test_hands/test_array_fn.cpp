#include <iostream>
#include <vector>

#include "cards.h"
#include "hands.h"


int main()
{
    Card c(Clubs, Two);
    Card d(Clubs, Three);
    Card e(Clubs, Two);

    std::vector<Card> cards{c,d,e};

    int snapper[13];
    value_scan_cards(cards, snapper);
    for (int i = 0; i < 13; i++)
        std::cout << snapper[i] << " ";

    std::cout << std::endl;
    return 0;

}
