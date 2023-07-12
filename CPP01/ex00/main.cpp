#include "Zombie.hpp"

void    randomChump(std::string name);

Zombie  *newZombie(std::string name);

int main(void)
{
    randomChump("Zé Carlos");
    Zombie *Zombie2 = newZombie("Maria José");
    Zombie2->announce();
    delete Zombie2;
    return (0);
}