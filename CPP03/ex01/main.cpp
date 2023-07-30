#include "ScavTrap.hpp"

int main()
{
    ScavTrap x ("Xavier");
    ScavTrap y ("Yasuo");
    ScavTrap z (y);

    y.setAttack(10);
    y.attack("Xavier");
    x.takeDamage(10);
    x.beRepaired(5);
    z.guardGate();

    return (0);
}