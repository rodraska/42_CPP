#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap x ("Xavier");
    DiamondTrap y ("Yasuo");
    DiamondTrap w = x;
    DiamondTrap z (y);

    std::cout << x;

    y.attack("Xavier");
    x.takeDamage(30);
    x.beRepaired(15);
    w.attack("z");
    z.takeDamage(30);
    z.beRepaired(20);
    z.whoAmI();

    std::cout << x;

    return (0);

}