#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default Constructor called\n";
    this->hit_pts = 100;
    this->eng_pts = 50;
    this->atk_pts = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
    std::cout << "ScavTrap Name Constructor called\n";
    this->name = name;
}

ScavTrap::ScavTrap(ScavTrap &s)
{
    std::cout << "ScavTrap Copy constructor called\n";
    *this = s;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &s)
{
    std::cout << "ScavTrap Copy assignment operator called\n";
    this->hit_pts = s.hit_pts;
    this->eng_pts = s.eng_pts;
    this->atk_pts = s.atk_pts;
    this->name = s.name;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->atk_pts << " points of damage\n";
    this->eng_pts--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode\n";
}