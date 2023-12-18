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
        test_int(str);
    else if ((s == 1 || (f == 1 && d > 8)) && str.size() == 1)
        test_char(str);
    else if (s == 1 || (f == 1 && d > 8))
        convertString(str);
    else if (p == 1 && f == 0)
        test_double(str);
    else if (p == 1 && f == 1)
        test_float(str);
}

void test_char(std::string str)
{
    char _char;

    std::istringstream iss(str);
    iss >> _char;
    std::cout << "char: '" << _char << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(_char) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(_char) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(_char) << std::endl;
}

void test_int(std::string str)
{   
    int _int;

    std::istringstream iss(str);
    iss >> _int;
    std::cout << "char: '" << static_cast<char>(_int) << "'" << std::endl;
    std::cout << "int: " << _int << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(_int) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(_int) << std::endl;
}

void test_float(std::string str)
{
    float _float;

    std::istringstream iss(str);
    iss >> _float;
    std::cout << "char: '" << static_cast<char>(_float) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(_float) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << _float << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(_float) << std::endl;
}

void test_double(std::string str)
{
    double _double;

    std::istringstream iss(str);
    iss >> _double;
    std::cout << "char: '" << static_cast<char>(_double) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(_double) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(_double) << "f" << std::endl;
    std::cout << "double: " << _double << std::endl;
}

void convertString(std::string str)
{
    (void)str;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (!str.compare("nan") || !str.compare("nanf"))
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if(!str.compare("-inff") || !str.compare("-inff"))
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if(!str.compare("+inff") || !str.compare("+inf"))
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
