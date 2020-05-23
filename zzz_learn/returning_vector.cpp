/* 
 *
 * It looks as though this method of concat works
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<int> l)
{
    for (auto i : l)
        std::cout << i << std::endl;
}

std::vector<int> concat_order(std::vector<int> a, std::vector<int> b)
{
    std::cout << "'a' array contains:" <<std::endl;
    print(a);
    std::cout << "'b' array contains:" <<std::endl;
    print(b);

    std::vector<int> nums(a);

    std::cout << "'nums' array contains:" <<std::endl;
    print(nums);

    // concat lists
    nums.insert(nums.end(), b.begin(), b.end());
    std::cout << "'nums'-appended contains:" <<std::endl;
    print(nums);
    

    std::sort(nums.begin(), nums.end());
    std::cout << "'nums'-sorted contains:" <<std::endl;
    print(nums);

    return nums;

}
int main()
{
    std::vector<int> a{1,2,3,4,5,6};
    std::vector<int> b{3,2,8,9};

    std::vector<int> c = concat_order(a,b);
    std::cout << "c - contains" <<std::endl;
    print(c);

}
