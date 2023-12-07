#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* arr, unsigned int len, void(*function)(T &elem))
{
    for (unsigned int i = 0; i < len; i++)
        function(arr[i]);
}

template <typename T>
void increase(T &elem)
{
    elem++;
}

#endif