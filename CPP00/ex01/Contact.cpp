#include "Contact.hpp"

void    Contact::NewContact(std::string a, std::string b, \
                            std::string c, std::string d, std::string e)
{
    first = a;
    last = b;
    nick = c;
    phone = d;
    dark = e;
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
    std::cout << this->first << std::endl;
    std::cout << this->last << std::endl;
    std::cout << this->nick << std::endl;
    std::cout << this->phone << std::endl;
    std::cout << this->dark << std::endl;
}
