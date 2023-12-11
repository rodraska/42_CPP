#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <vector>

std::vector<std::string> ft_split(std::string src, std::string del);
float   ft_stoi(std::string src);
int checkDate(std::string src);

#endif