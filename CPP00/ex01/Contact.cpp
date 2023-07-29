#include "Contact.hpp"

void    Contact::NewContact(std::string first, std::string last, \
                            std::string nick, std::string phone, std::string dark)
{
    this->first = first;
    this->last = last;
    this->nick = nick;
    this->phone = phone;
    this->dark = dark;
};

void    DisplayInfo(std::string str)
{
    int len;
    int i;

    len = 0;
    while (str[len])
        len++;
    if (len > 10)
    {
        i = -1;
        while (++i < 9)
            std::cout << str[i];
        std::cout << ".";
    }
    else
    {
        while(len < 10)
        {
            std::cout << " ";
            len++;
        }
        std::cout << str;  
    }
    std::cout << "|";
}

void Contact::PrintInfo(void)
{
    DisplayInfo(this->first);
    DisplayInfo(this->last);
    DisplayInfo(this->nick);
}

void Contact::CoutInfo(void)
{
    std::cout << "First Name: ";
    std::cout << this->first << std::endl;
    std::cout << "Last Name: ";
    std::cout << this->last << std::endl;
    std::cout << "Nickname: ";
    std::cout << this->nick << std::endl;
    std::cout << "Phone Number: ";
    std::cout << this->phone << std::endl;
    std::cout << "Darkest Secret: ";
    std::cout << this->dark << std::endl;
}
