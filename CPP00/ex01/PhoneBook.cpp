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
    if (first.size() == 0)
    {
        std::cout << "No Empty Arguments" << std::endl;
        return ;
    }
    last = ReadInput("Last Name: ");
    if (last.size() == 0)
    {
        std::cout << "No Empty Arguments" << std::endl;
        return ;
    }
    nick = ReadInput("Nickname: ");
    if (nick.size() == 0)
    {
        std::cout << "No Empty Arguments" << std::endl;
        return ;
    }
    phone = ReadInput("Phone Number: ");
    if (phone.size() == 0)
    {
        std::cout << "No Empty Arguments" << std::endl;
        return ;
    }
    dark = ReadInput("Darkest Secret: ");
    if (dark.size() == 0)
    {
        std::cout << "No Empty Arguments" << std::endl;
        return ;
    }

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
    std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;
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
        contacts[i].PrintSmall();
        std::cout << std::endl;
        i++;
    }
    try {
        index = std::stoi(ReadInput("index: "));
    }
    catch (const std::exception &ex) {
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    if (index < 8 && index < count && index >= 0)
        contacts[index].PrintBig();
    else
        std::cout << "Invalid Index" << std::endl;
}

void PhoneBook::RotateContacts(void)
{
    int i;

    i = 8;
    while (--i > 0)
        contacts[i] = contacts[i - 1];
}
