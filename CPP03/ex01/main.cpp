#include "ScavTrap.hpp"

int main()
{
    ScavTrap x ("Xavier");
    ScavTrap y ("Yasuo");
    ScavTrap w = x;
    ScavTrap z (y);

    y.setAttack(10);
    y.attack("Xavier");
    x.takeDamage(10);
    x.beRepaired(5);
    w.setAttack(3);
    w.attack("z");
    z.takeDamage(3);
    z.beRepaired(4);
    z.guardGate();

    std::cout << x;

    return (0);
}