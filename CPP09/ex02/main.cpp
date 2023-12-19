#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe merge;
    if (ac > 1)
    {
        merge.Parse(ac, av);
        merge.Divide();
        /* merge.Print(merge.getList("X1"));
        std::cout << "--------------" << std::endl;
        merge.Print(merge.getList("X2")); */
    }
    else
        std::cout << "Bad Arguments" << std::endl;
    return (0); 
}