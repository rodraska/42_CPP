#pragma once
#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    private:
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &f);
        FragTrap & operator = (const FragTrap &f);
        ~FragTrap();
        virtual void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif