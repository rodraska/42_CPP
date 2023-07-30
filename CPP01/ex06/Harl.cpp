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
    std::map<std::string, int> map
    {
        {"DEBUG", 1},
        {"INFO", 2},
        {"WARNING", 3},
        {"ERROR", 4}
    };

    int x;
    auto it = map.find(level);

    if (it != map.end())
        x = it->second;
    else
    {
        std::cout << "Probably complaining about insignificant problems\n";
        return ;
    }
        
    switch(x)
    {
        case 1:
            this->debug();
        case 2:
            this->info();
        case 3:
            this->warning();
        case 4:
            this->error();
    }
}