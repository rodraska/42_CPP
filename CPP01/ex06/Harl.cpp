#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
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
        std::cout << "Invalid Input\n";
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