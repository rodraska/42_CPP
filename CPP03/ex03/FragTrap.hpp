#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual ClapTrap
{
    protected:
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(FragTrap &f);
        FragTrap & operator = (const FragTrap &f);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif