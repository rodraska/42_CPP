#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cmath>

class Span
{
    private:
        std::vector<int> vec;
        size_t size;
    
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span & operator = (const Span &src);
        ~Span();

        void addNumber(int nbr);
        void addNumber(int begin, int end);
        size_t shortestSpan();
        size_t longestSpan();

        class VecFullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NoNumbersException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
