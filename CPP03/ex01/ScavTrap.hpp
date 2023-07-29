#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(ScavTrap &s);
        ScavTrap & operator = (const ScavTrap &s);
        ~ScavTrap();
        void attack(const std::string &target);
        void guardGate();

};

#endif