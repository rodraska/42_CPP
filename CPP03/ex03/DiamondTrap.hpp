#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
};

#endif