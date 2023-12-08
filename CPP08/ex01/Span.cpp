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

size_t Span::shortestSpan()
{
    if (vec.size() == 0)
        throw (NoNumbersException());

    size_t s_span = std::abs(vec[0] - vec[1]);

    for(size_t i = 0; i < vec.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if ((size_t)::abs(vec[i] - vec[j]) < s_span)
                s_span = std::abs(vec[i] - vec[j]);
        }
    }
    return (s_span);
}

size_t Span::longestSpan()
{
    if (vec.size() == 0)
        throw (NoNumbersException());
    
    size_t l_span = std::abs(vec[0] - vec[1]);

    for(size_t i = 0; i < vec.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if ((size_t)::abs(vec[i] - vec[j]) > l_span)
                l_span = std::abs(vec[i] - vec[j]);
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