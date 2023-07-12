#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout  << this->name << " was destroyed\n";
}