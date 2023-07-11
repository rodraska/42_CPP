#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     count = 0;
        void    RotateContacts(void);
    public:
        void    AddContact(void);
        void    SearchContacts(void);
        
    
};

#endif