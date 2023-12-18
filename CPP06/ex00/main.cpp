#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        //test_char(av[1]);
        //test_int(av[1]);
        //test_float(av[1]);
        //test_double(av[1]);
        ScalarConverter::convert(av[1]);
    }
    else
        std::cout << "Bad Arguments" << std::endl;
    return (0);
}