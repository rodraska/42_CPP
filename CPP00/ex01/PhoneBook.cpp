#include "PhoneBook.hpp"

void PhoneBook::AddContact(void)
{
    Contact contact;

    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string dark;

    std::cout << "First Name: ";
    std::cin >> first;
    std::cout << "Last Name: ";
    std::cin >> last;
    std::cout << "Nickname: ";
    std::cin >> nick;
    std::cout << "Phone Number: ";
    std::cin >> phone;
    std::cout << "Darkest Secret: ";
    std::cin >> dark;

    contact.NewContact(first, last, nick, phone, dark);
    if (count < 8)
        contacts[count] = contact;
    else
    {
        RotateContacts();
        contacts[0] = contact;
    }
    count++;
}

void PhoneBook::SearchContacts(void)
{
    int i;
    int index;

    i = 0;
    while (i < count && i < 8)
    {
        std::cout << "         " << i << "|";
        contacts[i].PrintInfo();
        std::cout << "\n";
        i++;
    }
    std::cout << "index: ";
    std::cin >> index;
    if (index < 8 && index < count)
        contacts[index].CoutInfo();
    else
        std::cout << "Invalid Index" << std::endl;
}

void PhoneBook::RotateContacts(void)
{
    int i;
    Contact tmp;

    i = 8;
    while (--i > 0)
        contacts[i] = contacts[i - 1];
}

