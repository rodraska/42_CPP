#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap
{
    private:
        std::string name;
        using FragTrap::hit_pts;
        using ScavTrap::eng_pts;
        using FragTrap::atk_pts;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &d);
        std::string getName() const;
        void whoAmI();
};

#endif