#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            ft_btc(av[1]);
        }
        catch (const MyCustomException& exc)
        {
            std::cerr << exc.what() << std::endl << std::flush;
        }
    }
    else
        std::cerr << "Bad Arguments" << std::endl;
    /* (void)ac;
    (void)av;
    std::vector<std::string> vec = getData("2003-06-08");
    std::cout << "vec[0]: " << vec[0] << std::endl;
    std::cout << "vec[1]: " << vec[1] << std::endl; */
    return (0);
}