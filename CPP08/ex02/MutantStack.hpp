#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <iterator>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack<T>() {};
        MutantStack(const MutantStack &src) {*this = src;};
        MutantStack & operator = (const MutantStack &src) 
        {
            this->c = src.c;
            return (*this);
        };
        ~MutantStack() {};

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin()
        {
            return (this->c.begin());
        }
        const_iterator cbegin()
        {
            return (this->c.cbegin());
        }
        iterator end()
        {
            return (this->c.end());
        }
        const_iterator cend()
        {
            return (this->c.cend());
        }
        reverse_iterator rbegin()
        {
            return (this->c.rbegin());
        }
        const_reverse_iterator crbegin()
        {
            return (this->c.crbegin());
        }
        reverse_iterator rend()
        {
            return (this->c.rend());
        }
        const_reverse_iterator crend()
        {
            return (this->c.crend());
        }
};

#endif