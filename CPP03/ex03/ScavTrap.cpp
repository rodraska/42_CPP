#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    this->hit_pts = 100;
    this->eng_pts = 50;
    this->atk_pts = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap Name Constructor called" << std::endl;
    this->hit_pts = 100;
    this->eng_pts = 50;
    this->atk_pts = 20;
    this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap &s) : ClapTrap()
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = s;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &s)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    this->hit_pts = s.hit_pts;
    this->eng_pts = s.eng_pts;
    this->atk_pts = s.atk_pts;
    this->name = s.name;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->atk_pts << " points of damage" << std::endl;
    this->eng_pts--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}