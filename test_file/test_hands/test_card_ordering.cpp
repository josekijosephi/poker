#include <iostream>
#include <vector>

#include "cards.h"
#include "hands.h"


int main()
{
    //    ordering works
    Card c(Clubs,Three);
    Card d(Diamonds,Two);

    std::vector<Card> cards{c,d};

    pretty_card_print(order_cards(cards, suit_order));
    pretty_card_print(order_cards(cards, value_order));

    return 0;

}

