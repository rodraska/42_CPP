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
        convertInt(str);
    else if ((s == 1 || (f == 1 && d > 8)) && str.size() == 1)
        converChar(str);
    else if (s == 1 || (f == 1 && d > 8))
        convertString(str);
    else if (p == 1 && f == 0)
        convertDouble(str);
    else if (p == 1 && f == 1)
        convertFloat(str);
}

void converChar(std::string str)
{
    int _int = static_cast<int>(str[0]);

    std::cout << "char: " << str << std::endl;
    std::cout << "int: " << _int << std::endl;
    std::cout << "float: " << _int << ".0f" << std::endl;
    std::cout << "double: " << _int << ".0" << std::endl;
}

void convertInt(std::string str)
{
    printChar(str);
    std::cout << "int: " << str << std::endl;
    std::cout << "float: " << str + ".0f" << std::endl;
    std::cout << "double: " << str + ".0" << std::endl;
}

void convertString(std::string str)
{
    (void)str;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (!str.compare("nan"))
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void convertDouble(std::string str)
{
    int i = 0;
    while (str[i] != '.')
        i++;
    printChar(str.substr(0, i));
    std::cout << "int: " << str.substr(0, i) << std::endl;
    std::cout << "float: " << str + "f" << std::endl;
    std::cout << "double: " << str << std::endl;
}

void convertFloat(std::string str)
{
    int i = 0;
    while (str[i] != '.')
        i++;
    printChar(str.substr(0, i));
    std::cout << "int: " << str.substr(0, i) << std::endl;
    std::cout << "float: " << str << std::endl;
    std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
}

void printChar(std::string str)
{
    int _int;

    std::istringstream iss(str);
    iss >> _int;


    if (_int > 0)
        std::cout << "char: '" << static_cast<char>(_int) << "'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
}