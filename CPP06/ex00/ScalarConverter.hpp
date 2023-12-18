#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

void convertInt(std::string str);
void convertString(std::string str);
void convertDouble(std::string str);
void convertFloat(std::string str);
void converChar(std::string str);
void printChar(std::string str);

void test_char(std::string str);
void test_int(std::string str);
void test_double(std::string str);
void test_float(std::string str);


class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter & operator = (const ScalarConverter &src);
        ~ScalarConverter();

        static void convert(std::string str);
};

#endif