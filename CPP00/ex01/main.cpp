#include "PhoneBook.hpp"

std::string ReadInput(std::string message)
{      
    std::string str;

    std::cout << message;
    std::getline(std::cin, str);
    
    return (str);
}

int main(void)
{
    std::string input;
    PhoneBook book;

    while (1)
    {
        input = ReadInput("input: ");
        if (!input.compare("EXIT"))
            break;
        else if (!input.compare("ADD"))
            book.AddContact();
        else if (!input.compare("SEARCH"))
            book.SearchContacts();
        else
            std::cout << "Invalid Input" << std::endl;
    }
}