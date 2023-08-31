#include "Zombie.hpp"

int main(void)
{
    Zombie *group = zombieHorde(5, "Josefina");

    int i = -1;
    while(++i < 5)
        group[i].announce();
    delete[] group;

    return (0);
}