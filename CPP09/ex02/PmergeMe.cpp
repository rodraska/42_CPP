#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : l_start(0), l_end(0), a_start(0), a_end(0) {}

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

int l_findPair(int value, std::list<std::pair<int, int> > pair_lst)
{
    int result;

    for (std::list<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
    {
        result = (value == it->first) ? it->second : (value == it->second) ? it->first : -2;
        if (result != -2)
            return (result);       
    }
    return (result);
}

int a_findPair(int value, std::deque<std::pair<int, int> > pair_lst)
{
    int result;

    for (std::deque<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
    {
        result = (value == it->first) ? it->second : (value == it->second) ? it->first : -2;
        if (result != -2)
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
    std::list<int> lX;
    std::deque<int> aX;
    std::string token;

    for (size_t i = 1; i < (size_t)ac; i++)
    {
        if (checkInt(av[i]))
        {
            lX.push_back(ft_stoi(av[i]));
            aX.push_back(ft_stoi(av[i]));
        }
        else
            throw (PmergeMe::BadArgumentsException());
    }
    if (!checkRepeat(lX))
            throw (PmergeMe::RepeatedArgumentsException());
    std::cout << "Before: ";
    l_printList(lX);
    l_Divide(lX);
    /* std::cout << "Before: ";
    a_printList(aX); */
    a_Divide(aX);
    double l_time = double(l_end - l_start) / CLOCKS_PER_SEC * 1000.0;
    double a_time = double(a_end - a_start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::list: " << l_time << " ms" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: " << a_time << " ms" << std::endl;
}

void PmergeMe::l_Divide(std::list<int> lst)
{
    std::list<std::pair<int, int> > pair_lst;
    int first;
    int second;

    l_start = clock(); 
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
    l_Swap(pair_lst);
}

void PmergeMe::l_Swap(std::list<std::pair<int, int> >& pair_lst)
{
    for (std::list<std::pair<int,int> >::iterator it = pair_lst.begin(); it !=pair_lst.end(); it++)
        (it->first > it->second ? std::swap(it->first, it->second) : void());
    l_insertMain(pair_lst);
}

void PmergeMe::l_insertMain(std::list<std::pair<int, int> >& pair_lst)
{
    std::list<int> main;
    main.push_back(pair_lst.begin()->second);
    for (std::list<std::pair<int,int> >::iterator pair_it = ++pair_lst.begin(); pair_it != pair_lst.end(); pair_it++)
    {
        std::list<int>::iterator main_it = main.begin();
        while (main_it != main.end())
        {
            if (pair_it->second < *main_it)
            {
                main.insert(main_it, pair_it->second);
                break ;
            }
            else
                main_it++;
        }
        if (main_it == main.end())
            main.push_back(pair_it->second);     
    }
    l_insertPend(pair_lst, main);
}

void PmergeMe::l_insertPend(std::list<std::pair<int, int> >& pair_lst, std::list<int>& main)
{
    int pair;
    for (std::list<std::pair<int,int> >::iterator pair_it = pair_lst.begin(); pair_it != pair_lst.end(); pair_it++)
    {
        pair = l_findPair(pair_it->first, pair_lst);
        std::list<int>::iterator main_it = main.begin();
        while (*main_it != pair && *main_it < pair_it->first)
            main_it++;
        if (pair_it->first != -1)
            main.insert(main_it, pair_it->first);
    }
    l_end = clock();
    std::cout << "After: ";
    l_printList(main);
}

void PmergeMe::l_printList(std::list<int> lst)
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::l_printPairs(std::list<std::pair<int, int> > pair_lst)
{
    for (std::list<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void PmergeMe::a_Divide(std::deque<int> lst)
{
    std::deque<std::pair<int, int> > pair_lst;
    int first;
    int second;

    a_start = clock();
    std::deque<int>::iterator it = lst.begin();
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
    a_Swap(pair_lst);
}

void PmergeMe::a_Swap(std::deque<std::pair<int, int> >& pair_lst)
{
    for (std::deque<std::pair<int,int> >::iterator it = pair_lst.begin(); it !=pair_lst.end(); it++)
        (it->first > it->second ? std::swap(it->first, it->second) : void());
    a_insertMain(pair_lst);
}

void PmergeMe::a_insertMain(std::deque<std::pair<int, int> >& pair_lst)
{
    std::deque<int> main;
    main.push_back(pair_lst.begin()->second);
    for (std::deque<std::pair<int,int> >::iterator pair_it = ++pair_lst.begin(); pair_it != pair_lst.end(); pair_it++)
    {
        std::deque<int>::iterator main_it = main.begin();
        while (main_it != main.end())
        {
            if (pair_it->second < *main_it)
            {
                main.insert(main_it, pair_it->second);
                break ;
            }
            else
                main_it++;
        }
        if (main_it == main.end())
            main.push_back(pair_it->second);     
    }
    a_insertPend(pair_lst, main);
}

void PmergeMe::a_insertPend(std::deque<std::pair<int, int> >& pair_lst, std::deque<int>& main)
{
    int pair;
    for (std::deque<std::pair<int,int> >::iterator pair_it = pair_lst.begin(); pair_it != pair_lst.end(); pair_it++)
    {
        pair = a_findPair(pair_it->first, pair_lst);
        std::deque<int>::iterator main_it = main.begin();
        while (*main_it != pair && *main_it < pair_it->first)
            main_it++;
        if (pair_it->first != -1)
            main.insert(main_it, pair_it->first);      
    }
    a_end = clock();
   /*  std::cout << "After: ";
    a_printList(main); */
}

void PmergeMe::a_printList(std::deque<int> lst)
{
    for (std::deque<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::a_printPairs(std::deque<std::pair<int, int> > pair_lst)
{
    for (std::deque<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
}

const char* PmergeMe::BadArgumentsException::what() const throw()
{
    return ("Bad Arguments");
}

const char* PmergeMe::RepeatedArgumentsException::what() const throw()
{
    return ("Repeated Arguments");
}
