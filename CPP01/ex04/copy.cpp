#include "copy.hpp"

void    ft_copy(std::string filename, std::string s1, std::string s2)
{
    std::fstream file1;
    std::fstream file2;

    file1.open(filename, std::ios::in);
    if (!file1)
        std::cout << "Could not read from file\n";

    file2.open(filename.append(".replace"), std::ios::out);
    if (!file2)
        std::cout << "could not open file to write\n";

    std::string str;
    std::string line;

    while (std::getline(file1, line))
    {
        str.append(line);
        if (!file1.eof())
            str.push_back('\n');
    }
    //std::cout << str << std::endl;

    int i = 0;
    std::string nova;
    while (i < str.length())
    {
        if (!str.compare(i, s1.length(), s1))
        {
            nova.append(s2);
            i += s1.length();
        }
        else
        {
            nova.push_back(str[i]);
            i++;
        }
    }

    file2 << nova; 
    //std::cout << nova << std::endl;
    file1.close();
    file2.close();

}