#include "BitcoinExchange.hpp"

int ft_btc(char* str)
{
    std::ifstream input_file;
    std::ifstream data_file;
    std::string input_line;
    std::vector<std::string> input_tokens;
    std::vector<std::string> data_tokens;

    if (!openFile(input_file, str))
        throw (MyCustomException("Cannot Open File"));
    while (std::getline(input_file, input_line))
    {
        input_tokens = ft_split(input_line, " | ");
        if (!checkConditions(input_tokens))
            continue ;
        if (!openFile(data_file, "data.csv"))
            throw (MyCustomException("Cannot Open File"));
        data_tokens = getData(input_tokens[0]);
        std::cout << input_tokens[0] << " => " << input_tokens[1] << " = " << ft_stoi(input_tokens[1]) *  ft_stoi(data_tokens[1]) << std::endl;
    }
    input_file.close();
    return (0);
}

std::vector<std::string> getData(std::string input_date)
{
    std::ifstream data_file;
    std::string data_line;
    std::vector<std::string> lines;
    
    if (!openFile(data_file, "data.csv"))
        throw (MyCustomException("Cannot Open File"));
    
    while (std::getline(data_file, data_line))
        lines.push_back(data_line);
    std::vector<std::string>::reverse_iterator it = lines.rbegin();
    std::vector<std::string> input_ymd = ft_split(input_date, "-");
    while (it++ != lines.rend())
    {
        std::vector<std::string> data_ymd = ft_split(ft_split(*it, ",")[0], "-");
        if (ft_stoi(data_ymd[0]) > ft_stoi(input_ymd[0]))
            continue ;
        if (ft_stoi(data_ymd[1]) > ft_stoi(input_ymd[1]))
            continue ;
        if (ft_stoi(data_ymd[2]) > ft_stoi(input_ymd[2]))
            continue ;
        break ;
    }
    data_file.close();
    return (ft_split(*it, ","));
}

int openFile(std::ifstream& file_stream, std::string file_name)
{
    file_stream.open(file_name.c_str());
    if (!file_stream.is_open())
        return (0);
    return (1);
}

int checkConditions(std::vector<std::string> tokens)
{
    double d;
    if (tokens[0] == "date")
        return (0);
    if (!checkDate(tokens[0]))
    {
        std::cout << "Error: bad input => " << tokens[0] << std::endl;
        return (0);
    }
    d = ft_stoi(tokens[1]);
    if (d < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (0);
    }
    else if (d > 2147483647.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (0);
    }
    return (1);
}

int checkDate(std::string src)
{
    std::vector<std::string> tokens = ft_split(src, "-");
    int year, month, day;
    year = (int)ft_stoi(tokens[0]);
    month = (int)ft_stoi(tokens[1]);
    day = (int)ft_stoi(tokens[2]);
    if (year < 2009 || month < 0 || day < 0 || month > 12 || day > 31)
        return (0);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (0);
    if (month == 2 && day > 29)
        return (0);
    return (1);
}

double   ft_stoi(std::string src)
{
    double num = 0;
    size_t len = src.length();
    size_t i = -1;
    int f = 0;
    double sign = 1.0;
    double div = 0.1;
    
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