#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

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

int findPair(int value, std::list<std::pair<int, int> > pair_lst)
{
    int result;

    for (std::list<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
    {
        result = (value == it->first) ? it->second : (value == it->second) ? it->first : -2;
        if (result != 2)
            return (result);   
    }
    return (result);
}

bool checkRepeat(const std::list<int>& lst)
{
    bool result;

    for (std::list<int>::const_iterator out_it = lst.begin(); out_it != --lst.end(); out_it++)
    {
        std::list<int>::const_iterator inn_it = out_it;
        inn_it++;
        for (; inn_it != lst.end(); ++inn_it)
        {
            result = (*inn_it == *out_it ? false : true);
            if (result == false)
                return (result);
        }
    }
    return (result);
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
    if (!checkRepeat(X))
    {
        std::cout << "Repeated Arguments" << std::endl;
        return ;
    }
    Divide(X);
}

void PmergeMe::Divide(std::list<int> lst)
{
    std::list<std::pair<int, int> > pair_lst;
    int first;
    int second;

    std::list<int>::iterator it = lst.begin();
    while (it != lst.end())
    {
        first = *(it++);
        if (std::distance(it, lst.end()) > 0)
        {
            second = *(it++);
            pair_lst.push_back(std::make_pair(first, second));
        }
        else
            pair_lst.push_back(std::make_pair(first, -1));    
    }
    Swap(pair_lst);
    //Compare(pair_lst);
}

void PmergeMe::Swap(std::list<std::pair<int, int> > pair_lst)
{
    printPairs(pair_lst);
    for (std::list<std::pair<int,int> >::iterator it = pair_lst.begin(); it !=pair_lst.end(); it++)
        (it->first > it->second ? std::swap(it->first, it->second) : void());
    printPairs(pair_lst);
}

void PmergeMe::Compare(std::list<std::pair<int, int> > pair_lst)
{
    std::list<int> big;
    std::list<int> small;
    for (std::list<std::pair<int,int> >::iterator it = pair_lst.begin(); it !=pair_lst.end(); it++)
        (it->first > it->second ? (big.push_back(it->first), small.push_back(it->second)) : (big.push_back(it->second), small.push_back(it->first)));
    if (big.size() > 2)
        Divide(big);
    else
    {   (big.front() > big.back() ? std::iter_swap(big.begin(), --big.end()) : void());
        int pair = findPair(big.front(), pair_lst);
        big.push_front(pair);
        small.remove(pair);
        Binary(big, small);
    }
}

void PmergeMe::Binary(std::list<int>& big, std::list<int>& small)
{
    
    std::list<int> copy_big = big;
    while (small.size() != 0)
    {
        std::list<int>::iterator it = copy_big.begin();
        size_t distance = std::distance(copy_big.begin(), copy_big.end()) / 2;
        for (size_t i = 0; i < distance; i++)
            it++;
    }
}

void PmergeMe::printList(std::list<int> lst)
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void PmergeMe::printPairs(std::list<std::pair<int, int> > pair_lst)
{
    for (std::list<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "--------------------------" << std::endl;
}
