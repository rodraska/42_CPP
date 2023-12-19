#include "PmergeMe.hpp"

int ft_stoi(std::string str)
{
    int num = 0;

    for (size_t i = 0; i < (size_t)str.length(); i++)
        num = num * 10 + (str[i] - 48);
    return (num);
}

bool checkInt(std::string str)
{
    for (size_t i = 0; i < (size_t)str.length(); i++)
    {
        if (str[i] < 48 || str[i] > 57)
            return (false);
    }
    return (true);
}

void PmergeMe::Parse(int ac, char **av)
{
    std::string token;
    n = ac - 1;

    for (size_t i = 1; i < (size_t)ac; i++)
    {
        if (checkInt(av[i]))
            X.push_back(ft_stoi(av[i]));
        else
        {
            std::cout << "Bad Arguments" << std::endl;
            return ;
        }
    }
}

void PmergeMe::Divide()
{
    std::list<int>::iterator it = X.begin();
    while (it != X.end())
    {
        if (std::next(it) != X.end())
        {
            int arr[2] = {*it, *std::next(it)};
            pairs.push_back(arr);
        }
        it++;
        it++;
    }
}

void PmergeMe::Print(std::list<int> lst)
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << std::endl;
}

std::list<int> PmergeMe::getList(std::string str)
{
    return std::list<int>();
}
