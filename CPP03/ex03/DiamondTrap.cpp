#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name)
{
    std::cout << "DiamondTrap Name Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d): FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = d;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap &d)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    this->hit_pts = d.hit_pts;
    this->eng_pts = d.eng_pts;
    this->atk_pts = d.atk_pts;
    this->name = d.name;
    return (*this);
}

std::string DiamondTrap::getName() const
{
    return (this->name);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap is called " << this->getName() << std::endl;
    std::cout << "Clap Trap is called " << ClapTrap::getName() << std::endl;
}