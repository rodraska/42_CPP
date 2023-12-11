#include "BitcoinExchange.hpp"

int checkDate(std::string src)
{
    std::vector<std::string> tokens = ft_split(src, "-");
    int year;
    int month;
    int day;
    year = (int)ft_stoi(tokens[0]);
    month = (int)ft_stoi(tokens[1]);
    day = (int)ft_stoi(tokens[2]);
    if (year < 0 || month < 0 || day < 0)
        return (0);
    if (month > 12)
        return (0);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (0);
    if (month == 2 && day > 29)
        return (0);
    if (day > 31)
        return (0);
    return (1);
}

float   ft_stoi(std::string src)
{
    float num = 0;
    size_t len = src.length();
    size_t i = -1;
    int f = 0;
    float sign = 1.0;
    float div = 0.1;
    
    while (++i < len)
    {
        if (src[i] == '-')
        {
            sign *= -1;
            continue ;
        }
        if (src[i] == '.')
        {
            f = 1;
            continue ;
        }
        if (f == 1)
        {
            num = num + (src[i] - 48) * div;
            div = div * 0.1;
        }
        else
            num = num * 10 + (src[i] - 48);
    }
    return (num * sign);
}

std::vector<std::string> ft_split(std::string src, std::string del)
{
    std::vector<std::string> tokens;
    size_t pos = 0;
    size_t len = del.length();

    while((pos = src.find(del)) != std::string::npos)
    {
        tokens.push_back(src.substr(0, pos));
        src.erase(0, pos + len);
    }
    tokens.push_back(src);
    return (tokens);
}