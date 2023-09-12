#pragma once
#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string name;
        int hit_pts;
        int eng_pts;
        int atk_pts;
    public:
        ClapTrap(); //Default Constructor
        ClapTrap(const std::string &name); //Name Constructor
        ClapTrap(const ClapTrap &c); //Copy Constructor
        ClapTrap & operator = (const ClapTrap &c); //Copy Assignment Operator
        ~ClapTrap(); //Destructor
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setAttack(unsigned int amount);
        std::string getName() const;
        int getHit() const;
        int getEng() const;
        int getAtk() const;
};

std::ostream & operator << (std::ostream &os, const ClapTrap &c);

#endif