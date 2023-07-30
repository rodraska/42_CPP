#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called\n";
    this->hit_pts = 10;
    this->eng_pts = 10;
    this->atk_pts = 0;
}

ClapTrap::ClapTrap(std::string &name)
{
    std::cout << "Name constructor called\n";
    this->name = name;
    this->hit_pts = 10;
    this->eng_pts = 10;
    this->atk_pts = 0;
}

ClapTrap::ClapTrap(ClapTrap &c)
{
    std::cout << "Copy constructor called\n";
    *this = c;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &c)
{
    std::cout << "Copy assignment operator called\n";
    this->hit_pts = c.hit_pts;
    this->eng_pts = c.eng_pts;
    this->atk_pts = c.atk_pts;
    this->name = c.name;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hit_pts == 0)
        std::cout << "ClapTrap " << this->name << " has not hit points\n";
    else if (this->eng_pts == 0)
        std::cout << "ClapTrap " << this->name << " has not energy points\n";
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->atk_pts << " points of damage\n";
        this->eng_pts--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_pts == 0)
        std::cout << "ClapTrap " << this->name << " has not hit points\n";
    else
    {
        std::cout << "ClapTrap " << this->name << " loses " << amount << " hit points\n";
        this->hit_pts -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->eng_pts == 0)
        std::cout << "ClapTrap " << this->name << " has not energy points\n";
    else
    {
        std::cout << "ClapTrap " << this->name << " gains " << amount << " hit points\n";
        this->eng_pts--;
        this->hit_pts += amount;
    }
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