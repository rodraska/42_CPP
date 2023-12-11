#include "BitcoinExchange.hpp"

int main(void)
{
    std::ifstream input_file("input.txt");
    if (!input_file.is_open())
    {
        std::cerr << "Could not open input file" << std::endl;
        return (2);
    }
    
    std::string input_line;
    std::string base_line;
    std::string input_del = " | ";
    std::string base_del = ",";
    float input_float;
    float base_float;
    float final_float;
    while (std::getline(input_file, input_line))
    {
        std::ifstream data_base("data.csv");
        if (!data_base.is_open())
        {
            std::cerr << "Could not open data base" << std::endl;
            return (1);
        }
        std::vector<std::string> input_vec = ft_split(input_line, input_del);
        while (std::getline(data_base, base_line))
        {
            std::vector<std::string> base_vec = ft_split(base_line, base_del);
            if (input_vec[0] == base_vec[0] && input_vec[0] != "date")
            {
                input_float = ft_stoi(input_vec[1]);
                base_float = ft_stoi(base_vec[1]);
                final_float = input_float * base_float;
                if (final_float < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if (final_float > 2147483647.0)
                    std::cout << "Error: too large a number." << std::endl;
                else if (!checkDate(input_vec[0]))
                    std::cout << "Error: bad input => " << input_vec[0] << std::endl;    
                else
                    std::cout << input_vec[0] << " => " << input_float << " = " << final_float << std::endl;
            }
        }
        data_base.close();
    }
        

    /* std::string base_line;
    while (std::getline(data_base, base_line))
        std::cout << base_line << std::endl; */

    return (0);
}