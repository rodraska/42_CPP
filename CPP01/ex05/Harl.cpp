#include "Harl.hpp"

Harl::Harl()
{
    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";

    this->function[0] = &Harl::debug;
    this->function[1] = &Harl::info;
    this->function[2] = &Harl::warning;
    this->function[3] = &Harl::error;
}

Harl::~Harl()
{
    std::cout << "Harl was destroyed" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    for(int i = 0; i < 4; i++)
    {
        if (level == this->levels[i])
        {
            (this->*function[i])();
            return ;
        }       
    }
    std::cout << "Invalid Input" << std::endl;
}

/* void Harl::complain(std::string level)
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
        std::cout << "Invalid Input" << std::endl;
} */