#include "hands.h"

int main ()
{
    // Hand 1
    std::vector<Card> hand1{ Card(Clubs, Two),Card(Clubs, Three),Card(Hearts, Four),Card(Clubs, Five),Card(Clubs, Six) };
    std::cout << "This is the first hand" << std::endl;
    pretty_card_print(hand1);

    // Hand 2
    std::vector<Card> hand2{ Card(Hearts, Ace), Card(Diamonds, Ace), Card(Clubs, Ace), Card(Hearts, Two), Card(Clubs,Two) };
    std::cout << "This is the second hand" << std::endl;
    pretty_card_print(hand2);
    

    std::string winning_hands[] = {"Straight Flush", "Four of a Kind", "Full House", 
        "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair", "High Card"};

    Hand h1_hand = find_hand(hand1).get_hand();
    Hand h2_hand = find_hand(hand2).get_hand();
    
    std::cout << "Hand-1 is a hand " << winning_hands[(int)h1_hand] << ", and Hand-2 is " << winning_hands[(int)h2_hand] << std::endl;
    
}
