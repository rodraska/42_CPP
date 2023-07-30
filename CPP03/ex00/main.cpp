#include "ClapTrap.hpp"

int main()
{
    std::string name1 = "Alberta";
    std::string name2 = "Bernie";

    ClapTrap a(name1);
    ClapTrap b(name2);
    ClapTrap c (b);

    b.setAttack(10);
    b.attack("Alberta");
    a.takeDamage(10);
    a.beRepaired(5);

    std::cout << a;

    return (0);
}