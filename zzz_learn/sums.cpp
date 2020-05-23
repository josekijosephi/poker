#include <vector>
#include <iostream>
void print(std::vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << (*it) << std::endl;
}

class functions
{

    public:
        functions() {};
        int (functions::*mem_func_ptr)(int, int);
        int add(int a, int b) { return a + b; }
        int dif(int a, int b) { return a - b; }
        int mul(int a, int b) { return a * b; }

};


int main()
{

    // Array of function pointers -- training
    int (functions::*operation[])(int,int) = { &functions::add, &functions::dif, &functions::mul };

    functions func;

    for (auto fp : operation)
    {
        func.mem_func_ptr = fp;
        std::cout << (func.*(func.mem_func_ptr))(10,5) << std::endl;
        if ((func.*(func.mem_func_ptr))(10,5) < 10)
            break;
    }

    return 0;
}

/*
 * This is how i learnt to put the first element into position one

    std::cout << "my_nums contains the following numbers:" << std::endl;
    for (std::vector<int>::iterator it = my_nums.begin();
            it != my_nums.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Now after doing the switch:" << std::endl;
    int num = my_nums.back();
    my_nums.pop_back();

    auto it = my_nums.insert(my_nums.begin(), num);
    for (std::vector<int>::iterator it = my_nums.begin();
            it != my_nums.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
*/
