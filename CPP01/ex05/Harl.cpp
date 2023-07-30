#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG: Paulinho is a really good player. He's the perfect player for the forward position" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: I can't believe Paulinho missed that shot. It was so easy!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: If Paulinho doesn't score today he has to go to the bench. This has been too much!" << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: BUUUUUUUUUUU TIRA O PAULINHO CRL" << std::endl;
}

void Harl::complain(std::string level)
{
    std::map<std::string, std::function<void()>> map
    {
        {"DEBUG", std::bind(&Harl::debug, this)},
        {"INFO", std::bind(&Harl::info, this)},
        {"WARNING", std::bind(&Harl::warning, this)},
        {"ERROR", std::bind(&Harl::error, this)}
    };

    auto it = map.find(level);

    if (it != map.end())
        it->second();
    else
        std::cout << "Invalid Input\n";
}