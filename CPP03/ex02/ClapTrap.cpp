#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    this->hit_pts = 10;
    this->eng_pts = 10;
    this->atk_pts = 0;
}

ClapTrap::ClapTrap(const std::string &name) : name(name)
{
    std::cout << "Name constructor called" << std::endl;
    this->hit_pts = 10;
    this->eng_pts = 10;
    this->atk_pts = 0;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = c;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->hit_pts = c.hit_pts;
    this->eng_pts = c.eng_pts;
    this->atk_pts = c.atk_pts;
    this->name = c.name;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->atk_pts << " points of damage" << std::endl;
    this->eng_pts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " is attacked " << "losing " << amount << " hit points" << std::endl;
    this->hit_pts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " is repaired " << "gaining " << amount << " hit points" << std::endl;
    this->eng_pts--;
    this->hit_pts += amount;
}

void ClapTrap::setAttack(unsigned int amount)
{
    this->atk_pts = amount;
}

std::string ClapTrap::getName () const
{
    return (this->name);
}

int ClapTrap::getHit () const
{
    return (this->hit_pts);
}

int ClapTrap::getEng () const
{
    return (this->eng_pts);
}

int ClapTrap::getAtk () const
{
    return (this->atk_pts);
}

std::ostream & operator << (std::ostream &os, const ClapTrap &c)
{
    os << "Name: " << c.getName() << std::endl;
    os << "Hit Points: " << c.getHit() << std::endl;
    os << "Energy Points: " << c.getEng() << std::endl;
    os << "Attack Points: " << c.getAtk() << std::endl;
    return (os);
}