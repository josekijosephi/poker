#include <algorithm>
#include <iostream>

#include "hands.h"


int value_order (Card c, Card d)
{
    return c.get_value() <= d.get_value(); 
}

int suit_order (Card c, Card d)
{
    return c.get_suit() <= d.get_suit();
}

int longest_increasing_sequence(int *vals_list)
{
    // This gets passed the array from scan_cards
    int count = 0;
    int previous_value = -1;
    int length_longest = 0;

    for (int i = 0; i < NUM_VALUES; i++)
    {
        if (vals_list[i]) // there is a value in array
        {
            if (vals_list[i] - previous_value == 1) // ie follows the previous
                previous_value = vals_list[i];
            else if (previous_value == -1)
                previous_value = vals_list[i];

            count++;

            length_longest = (count > length_longest) ? count : length_longest;

        } else // a streak has been broken
            count = 0;
    }

    return length_longest;
}

void suit_scan_cards(std::vector<Card> cards, int *num_suit)
{

    for (int i = 0; i < NUM_SUITS; i++)
        num_suit[i] = 0;

    for (auto it = cards.begin(); it != cards.end(); ++it)
        num_suit[(*it).get_suit()]++;
}

void value_scan_cards(std::vector<Card> cards, int *num_vals)
{

    for (int i = 0; i < NUM_VALUES; i++)
        num_vals[i] = 0;

    for (auto it = cards.begin(); it != cards.end(); ++it)
        num_vals[(*it).get_value()]++;
}

int is_flush(int *num_suit)
{
    for (int i = 0; i < NUM_SUITS; i++)
        if (num_suit[i] == 5)
            return 1;

    return 0;
}
int is_straight(int *num_vals)
{
    return (longest_increasing_sequence(num_vals) >= 5);
}
int max_of_one_card(int *num_vals)
{
    int max_count = 0;
    for (int i = 0; i < NUM_VALUES; i++)
        max_count = (num_vals[i] > max_count) ? num_vals[i] : max_count;
    return max_count;
}
int is_pair(int *num_vals)
{
    for (int i = 0; i < NUM_VALUES; i++)
        if (num_vals[i] == 2)
            return 1;

    return 0;
}
int is_two_pair (int *num_vals)
{
    int num_pairs = 0;
    for (int i = 0; i < NUM_VALUES; i++)
        num_pairs += (num_vals[i] == 2);

    return (num_pairs >= 2);
}
int is_three_kind(int *num_vals)
{
    for (int i = 0; i < NUM_VALUES; i++)
        if (num_vals[i] == 3)
            return 1;

    return 0;
}

int Hand_order (Hand_Value a, Hand_Value b)
{
    if (a.get_hand() == b.get_hand())
        return (a.get_top_value() < b.get_top_value());
    else
        // Since the best hand has value 0, lower is better
        return (a.get_hand() < b.get_hand());
}

Value greater_card(Card a, Card b)
{
    if (a.get_value() >= b.get_value())
        return a.get_value();
    else
        return b.get_value();
}

Hand_Value find_hand(std::vector<Card> cards)
{
    int suit_count[NUM_SUITS];
    int valu_count[NUM_VALUES];

    suit_scan_cards(cards, suit_count);
    value_scan_cards(cards, valu_count);

    Hand_Value value_of_hand;

    // need to find which pocket card has the greater value
    value_of_hand.set_top_value(
            greater_card(cards.at(cards.size()-1), cards.at(cards.size()-2))
            );

    if (is_flush(suit_count) && is_straight(valu_count))
        value_of_hand.set_hand(Straight_Flush);
    else if (max_of_one_card(valu_count) == 4)
        value_of_hand.set_hand(Four_Kind);
    else if (is_three_kind(valu_count) && is_pair(valu_count))
        value_of_hand.set_hand(Full_House);
    else if (is_flush(suit_count))
        value_of_hand.set_hand(Flush);
    else if (is_straight(valu_count))
        value_of_hand.set_hand(Straight);
    else if (is_three_kind(valu_count))
        value_of_hand.set_hand(Three_Kind);
    else if (is_two_pair(valu_count))
        value_of_hand.set_hand(Two_Pair);
    else if (is_pair(valu_count))
        value_of_hand.set_hand(One_Pair);

    return value_of_hand;
}


std::vector<Card> return_winning_hand(std::vector<Card> cards, 
        std::vector<Card> pocket_cards, Hand_Value hand)
{

    // Add pocket cards to comm cards
    cards.insert(cards.end(), pocket_cards.begin(), pocket_cards.end());

    if (hand.get_hand() == Flush)
        // Now re-order cards based off type of hand
        std::sort(cards.begin(), cards.end(), suit_order);
    else
        std::sort(cards.begin(), cards.end(), value_order);

    return cards;
}
