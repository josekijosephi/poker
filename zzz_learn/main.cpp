#include <iostream>

#include "add.hpp"
// In C++, we use a header file to save this
// forward declaration of functions
// int add (int x, int y);


int main (void)
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';

    return 0;
}
