#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
    std::cout << "DiamondTrap Name Constructor called" << std::endl;
    this->hit_pts = FragTrap::hit_pts;
    this->eng_pts = ScavTrap::eng_pts;
    FragTrap::atk_pts = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d): ClapTrap(d.name), FragTrap(d.name), ScavTrap(d.name)
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

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond Trap destroyed" << std::endl;
}

const std::string DiamondTrap::getName() const
{
    return (this->name);
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap is called " << this->getName() << std::endl;
}