#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 2)
            ft_btc(av[1]);
        else
            throw (MyCustomException("Error: could not open file"));
    }
    catch (std::exception &exc)
    {
        std::cerr << exc.what() << std::endl << std::flush;
    }
    return (0);
}