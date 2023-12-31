#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Default Constructor called" << std::endl;
    this->hit_pts = 100;
    this->eng_pts = 100;
    this->atk_pts = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap Name Constructor called" << std::endl;
    this->hit_pts = 100;
    this->eng_pts = 100;
    this->atk_pts = 30;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap()
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = f;
}

FragTrap & FragTrap::operator = (const FragTrap &f)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    this->hit_pts = f.hit_pts;
    this->eng_pts = f.eng_pts;
    this->atk_pts = f.atk_pts;
    this->name = f.name;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->atk_pts << " points of damage" << std::endl;
    this->eng_pts--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Give me a high five guys!\n";
}

