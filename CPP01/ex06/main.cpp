#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harl;
        harl.complain(av[1]);
    }
    else
        std::cout << "Invalid Input\n";

    return (0);
}