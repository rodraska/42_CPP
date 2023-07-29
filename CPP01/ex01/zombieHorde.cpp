#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *group = new Zombie[N];

    int i = -1;
    while (++i < N)
        group[i].setName(name);
    
    return (group);
}