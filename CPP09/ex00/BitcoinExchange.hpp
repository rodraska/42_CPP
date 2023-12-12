#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <exception>
# include <cstring>


int ft_btc(char* str);
std::vector<std::string> ft_split(std::string src, std::string del);
double   ft_stoi(std::string src);
int checkDate(std::string src);
int openFile(std::ifstream& file_stream, std::string file_name);
int checkConditions(std::vector<std::string> tokens);
std::vector<std::string> getData(std::string input_date);

class MyCustomException : public std::exception
{
    private:
        char _message[256];
    public:
        MyCustomException(const char* message) 
        {
            std::strncpy(_message, message, strlen(message));
            _message[strlen(message)] = '\0';
        }
        virtual const char* what() const throw()
        {
            return (_message);
        }
};

#endif