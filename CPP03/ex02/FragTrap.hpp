#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &f);
        FragTrap & operator = (const FragTrap &f);
        ~FragTrap();
        void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif