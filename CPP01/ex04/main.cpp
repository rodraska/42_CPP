#include "copy.hpp"

void    ft_copy(std::string filename, std::string s1, std::string s2);

int main(int ac, char **av)
{
    if (ac == 4)
        ft_copy(av[1], av[2], av[3]);
    else
        std::cout << "Invalid Input" << std::endl;

}