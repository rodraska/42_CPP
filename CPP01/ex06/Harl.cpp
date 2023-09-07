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
    int i = 0;
    for (i; i < 4; i++)
    {
        if (level == this->levels[i])
            break ;
    }

    if (i == 4)
    {
        std::cout << "Invalid Input" << std::endl;
        return ;
    }
        
    switch(i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
    }
}