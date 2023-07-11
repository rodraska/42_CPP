#include "Zombie.hpp"

Zombie  *newZombie(std::string name);

void    randomChump(std::string name)
{
    Zombie myZombie;

    myZombie.setName(name);
    myZombie.announce();
}