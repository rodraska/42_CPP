#include "FragTrap.hpp"

int main()
{
    FragTrap x ("Xavier");
    FragTrap y ("Yasuo");
    FragTrap w = x;
    FragTrap z (y);

    y.setAttack(10);
    y.attack("Xavier");
    x.takeDamage(10);
    x.beRepaired(5);
    w.setAttack(3);
    w.attack("z");
    z.takeDamage(3);
    z.beRepaired(4);
    z.highFivesGuys();

    std::cout << x;

    return (0);
}