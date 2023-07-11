#include "PhoneBook.hpp"

int main(void)
{
    std::string input;
    PhoneBook book;
    int       count;

    count = 0;
    while (input.compare("EXIT") != 0)
    {
        std::cout << "input: ";
        std::cin >> input;
        if (!input.compare("ADD"))
        {
            book.AddContact();
            count++;
        }
            
        else if (!input.compare("SEARCH"))
        {
            book.SearchContacts();
        }
    }
}