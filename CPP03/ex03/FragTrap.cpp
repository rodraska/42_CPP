#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default Constructor called\n";
    this->hit_pts = 100;
    this->eng_pts = 100;
    this->atk_pts = 30;
}

FragTrap::FragTrap(const std::string &name)
{
    std::cout << "FragTrap Name Constructor called\n";
    this->name = name;
    this->hit_pts = 100;
    this->eng_pts = 100;
    this->atk_pts = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called\n";
}

FragTrap::FragTrap(FragTrap &f)
{
    std::cout << "FragTrap Copy constructor called\n";
    *this = f;
}

FragTrap & FragTrap::operator = (const FragTrap &f)
{
    std::cout << "FragTrap Copy assignment operator called\n";
    this->hit_pts = f.hit_pts;
    this->eng_pts = f.eng_pts;
    this->atk_pts = f.atk_pts;
    this->name = f.name;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Give me a high five guys!\n";
}

