#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &d);
        DiamondTrap & operator = (const DiamondTrap &d);
        ~DiamondTrap();
        const std::string getName() const;
        virtual void attack(const std::string &target);
        void whoAmI();
};

#endif