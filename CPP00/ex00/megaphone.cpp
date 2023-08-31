#include <iostream>
#include <string>

int main(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (++i < ac)
    {
        j = -1;
        while(av[i][++j])
        {
            if (av[i][j] >= 97 && av[i][j] <= 122)
                av[i][j] = toupper(av[i][j]);
            std::cout << av[i][j];
        }
        
    }
    std::cout << std::endl;
}