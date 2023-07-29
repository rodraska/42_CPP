#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *weapon;
        std::string name;
    public:
        void attack();
        void setWeapon(Weapon &weapon);
        HumanB(std::string name);
};

#endif