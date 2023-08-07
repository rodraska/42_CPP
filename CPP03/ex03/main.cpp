#include "FragTrap.hpp"

int main()
{
    FragTrap x ("Xavier");
    FragTrap y ("Yasuo");
    FragTrap z (y);

    y.setAttack(10);
    y.attack("Alberta");
    x.takeDamage(10);
    x.beRepaired(5);
    z.highFivesGuys();

    return (0);
}