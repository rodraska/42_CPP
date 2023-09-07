#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

void HumanB::attack()
{
    if (!this->weapon)
        std::cout << "You're out of bullets soldier" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}