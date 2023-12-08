#include "Span.hpp"

int main(void)
{
    {
        std::cout << "------------------------------------" << std::endl;
        try
        {
            Span sp = Span(5);

            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
    {
        std::cout << "------------------------------------" << std::endl;
        try
        {
            Span sp = Span(10000);

            for (int i = 0; i < 10000; i ++)
                sp.addNumber(i);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
    {
        std::cout << "------------------------------------" << std::endl;
        try
        {
            Span sp = Span(5);

            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            sp.addNumber(4);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
    {
        std::cout << "------------------------------------" << std::endl;
        try
        {
            Span sp = Span(5);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
        std::cout << "------------------------------------" << std::endl;
    }
    return (0);
}