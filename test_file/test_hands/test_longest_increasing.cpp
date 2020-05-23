#include <iostream>
#include <vector>

#include "cards.h"
#include "hands.h"

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

void value_scan_cards(std::vector<Card> cards, int *num_vals)
{

    for (int i = 0; i < NUM_VALUES; i++)
        num_vals[i] = 0;

    for (auto it = cards.begin(); it != cards.end(); ++it)
        num_vals[(*it).get_value()]++;
}


int main()
{
    Card c(Clubs, Two);
    Card d(Clubs, Three);
    Card e(Clubs, Two);

    Card f(Clubs, Ten);
    Card g(Clubs, Jack);
    Card h(Clubs, Queen);

    std::vector<Card> cards{c,d,e,f,g,h};

    int snapper[13];
    scan_cards(cards, snapper);

    std::cout << "The following array -" << std::endl;
    for (int i = 0; i < 13; i++)
        std::cout << snapper[i] << " ";
    std::cout << std::endl;

    std::cout << "Has a longest increasing sequence of " << longest_increasing_sequence(snapper) << std::endl;

    return 0;

}
