#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N)
{
    this->size = N;
}

Span::Span(const Span &src)
{
    *this = src;
}

Span & Span::operator = (const Span &src)
{
    this->size = src.size;
    for (size_t i = 0; i < src.vec.size(); i++)
        this->vec[i] = src.vec[i];
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int nbr)
{
    if ((size_t)vec.size() != size)
        vec.push_back(nbr);
    else
        throw (VecFullException());
}

void Span::addNumber(int begin, int end)
{
    if (begin > end)
        throw (NoNumbersException());
    for (int i = begin; i <= end; i++)
    {
        if ((size_t)vec.size() != size)
            vec.push_back(i);
        else
            throw (VecFullException());
    }
}

size_t Span::shortestSpan()
{
    if (vec.size() == 0)
        throw (NoNumbersException());

    std::vector<int> tmp = vec;
    std::vector<int>::iterator tmp_it = vec.begin();
    int first = *(tmp_it++);
    int second = *tmp_it;
    size_t s_span = std::abs(first - second);

    for(std::vector<int>::iterator out_it = vec.begin(); out_it != vec.end(); out_it++)
    {
        std::vector<int>::iterator inn_it = out_it;
        inn_it++;
        for (; inn_it != vec.end(); ++inn_it)
        {
            if ((size_t)std::abs((*out_it) - (*inn_it)) < s_span)
                s_span = std::abs((*out_it) - (*inn_it));
        }
    }
    return (s_span);
}


size_t Span::longestSpan()
{
    if (vec.size() == 0)
        throw (NoNumbersException());
    
    size_t l_span = 0;

    for(std::vector<int>::iterator out_it = vec.begin(); out_it != vec.end(); out_it++)
    {
        std::vector<int>::iterator inn_it = out_it;
        inn_it++;
        for (; inn_it != vec.end(); ++inn_it)
        {
            if ((size_t)std::abs((*out_it) - (*inn_it)) > l_span)
                l_span = std::abs((*out_it) - (*inn_it));
        }
    }
    return (l_span);
}

const char* Span::VecFullException::what() const throw()
{
    return ("Vec cannot accept any more numbers");
}

const char* Span::NoNumbersException::what() const throw()
{
    return ("No numbers in Vec");
}