#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe merge;
    if (ac > 1)
        merge.Parse(ac, av);
    else
        std::cout << "Bad Arguments" << std::endl;
    return (0); 
}