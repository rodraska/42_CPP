#pragma once
#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    protected:
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &s);
        ScavTrap & operator = (const ScavTrap &s);
        ~ScavTrap();
        virtual void attack(const std::string &target);
        void guardGate();

};

#endif