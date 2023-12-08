#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <vector>

template <typename T>
void easyfind(T &t, int i)
{   
    size_t j = 0;
    for (;j < (size_t)t.size(); j++)
    {
        if (t[j] == i)
            break ;
    }
    if (j != t.size())
        std::cout << "index: " << j << std::endl;
    else
        throw (std::logic_error("Not Found"));
}

#endif
