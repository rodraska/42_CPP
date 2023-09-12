#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alberta");
    ClapTrap b("Bernie");
    ClapTrap c (a);
    ClapTrap d;

    d = b;

    b.setAttack(10);
    b.attack("Alberta");
    a.takeDamage(10);
    a.beRepaired(5);

    std::cout << a;

    return (0);
}