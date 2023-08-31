#include "Zombie.hpp"

int main(void)
{
    randomChump("Zé Carlos");
    Zombie *Zombie2 = newZombie("Maria José");
    Zombie2->announce();
    delete Zombie2;
    return (0);
}