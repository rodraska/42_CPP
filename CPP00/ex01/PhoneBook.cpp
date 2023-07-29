#include "PhoneBook.hpp"

std::string ReadInput(std::string message);

void PhoneBook::AddContact(void)
{
    Contact contact;

    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string dark;

    first = ReadInput("First Name: ");
    last = ReadInput("Last Name: ");
    nick = ReadInput("Nickname: ");
    phone = ReadInput("Phone Number: ");
    dark = ReadInput("Darkest Secret: ");

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

void FirstRow()
{
    std::cout << "     Index|First Name| Last Name|  Nickname|\n";
}

void PhoneBook::SearchContacts(void)
{
    int i;
    int index;

    i = 0;
    FirstRow();
    while (i < count && i < 8)
    {
        std::cout << "         " << i << "|";
        contacts[i].PrintInfo();
        std::cout << "\n";
        i++;
    }
    try {
        index = std::stoi(ReadInput("index: "));
    }
    catch (const std::exception &ex) {
        std::cout << "Invalid Index\n";
        return;
    }
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

