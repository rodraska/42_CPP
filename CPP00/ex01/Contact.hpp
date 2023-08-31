#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
    private:
        std::string first;
        std::string last;
        std::string nick;
        std::string phone;
        std::string dark;
    public:
        void    NewContact(std::string first, std::string last, \
                           std::string nick, std::string phone, std::string dark);
        void    PrintSmall();
        void    PrintBig();
};

#endif