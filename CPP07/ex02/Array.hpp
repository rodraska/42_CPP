#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array
{
    public:
        T* t;
        unsigned int len;

        Array()
        {
            t = new T();
            len = 0;
        }
        Array(unsigned int n)
        {
            t = new T[n];
            len = n;
        }
        Array(const Array &src)
        {
            t = new T[src.len];
            len = src.len;
            *this = src;
        }
        Array & operator = (const Array &src)
        {
            delete[] t;
            t = new T[src.len];
            len = src.len;
            for (unsigned int i = 0; i < len; i++)
                t[i] = src.t[i];
            return (*this);
        }
        ~Array()
        {
            delete[] t;
        }
        T & operator [] (unsigned int i)
        {
            if (i >= len)
            {
                throw (std::out_of_range("Accessing out of bounds index"));
            }
            return (t[i]);
        }
        unsigned int size()
        {
            return (len);
        }
};

#endif