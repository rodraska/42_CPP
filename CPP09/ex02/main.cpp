#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe merge;
    try
    {
        if (ac > 1)
            merge.Parse(ac, av);
        else
            throw(PmergeMe::BadArgumentsException());
    }
    catch(std::exception &exc)
    {
        std::cerr << exc.what() << std::endl;
    }
    return (0); 
}