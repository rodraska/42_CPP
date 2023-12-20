#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <vector>

template <typename T>
void easyfind(T &t, int i)
{   
    typename T::iterator it = t.begin();
    int k = 0;
    for (; it != t.end(); it++)
    {
        if (*it == i)
            break ;
        k++;
    }
    if (it != t.end())
        std::cout << "index: " << k << std::endl;
    else
        throw (std::logic_error("Not Found"));
}

#endif
