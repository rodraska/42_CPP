#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
    Zombie *group = new Zombie[n];

    int i = -1;
    while (++i < n)
        group[i].setName(name);
    
    return (group);
}