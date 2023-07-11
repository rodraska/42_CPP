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
        void    NewContact(std::string a, std::string b, \
                           std::string c, std::string d, std::string e);
        void    PrintInfo();
        void    CoutInfo();
    };

#endif