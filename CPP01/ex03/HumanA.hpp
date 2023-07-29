#pragma once
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
    private:
        Weapon &weapon;
        std::string name;
    public:
        void attack();
        HumanA(std::string name, Weapon &weapon);
};

#endif