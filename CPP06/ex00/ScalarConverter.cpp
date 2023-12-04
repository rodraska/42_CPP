#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter &src)
{
    (void)src;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
    int _int;

    std::istringstream iss(str);
    iss >> _int;

    std::cout << "char: '" << static_cast<char>(_int) << "'" << std::endl;
    std::cout << "int: " << _int << std::endl;
    std::cout << "float: " << _int << ".0f" << std::endl;
    std::cout << "double: " << _int << ".0" << std::endl;
}

void checkType(std::string str)
{
    int p = 0;
    int s = 0;
    int f = 0;
    int d = 0;

    for (unsigned long i = 0; i < str.size(); i++)
    {
        if (p == 1)
            d++;
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue ;
        if (str[i] == '.' && i != str.size() - 1)
            p = 1;
        else if (i == str.size() - 1 && str[i] == 'f' && p == 1 && d < 9)
            f = 1;
        else if (str[i] < '0' || str[i] > '9' || (str[i] == '.' && p == 1))
        {
            s = 1;
            break ;
        }
    }

    if (p == 0 && f == 0 && s == 0)
    {
        std::cout << "Int" << std::endl;
        convertInt(str);
    }
    else if (s == 1 || (f == 1 && d > 8))
    {
        std::cout << "String" << std::endl;
        convertString(str);
    }
    else if (p == 1 && f == 0)
    {
        std::cout << "Double" << std::endl;
        convertDouble(str);
    }
    else if (p == 1 && f == 1)
    {
        std::cout << "Float" << std::endl;
        convertFloat(str);
    }
}

void convertInt(std::string str)
{
    std::cout << "int: " << str << std::endl;
    std::cout << "float: " << str + ".0f" << std::endl;
    std::cout << "double: " << str + ".0" << std::endl;
}

void convertString(std::string str)
{
    (void)str;
}

void convertDouble(std::string str)
{
    int i = 0;
    while (str[i] != '.')
        i++;
    std::cout << "int: " << str.substr(0, i) << std::endl;
    std::cout << "float: " << str + "f" << std::endl;
    std::cout << "double: " << str << std::endl;
}

void convertFloat(std::string str)
{
    int i = 0;
    while (str[i] != '.')
        i++;
    std::cout << "int: " << str.substr(0, i) << std::endl;
    std::cout << "float: " << str << std::endl;
    std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
}