#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 25, 5), _target("Default")
{   
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 25, 5), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : _target(src.getTarget())
{
    *this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &src)
{
    if (this == &src)
        return (*this);
    this->_target = src.getTarget();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    this->checkExecute(executor);
    
    std::ofstream out_file;
    std::string file_name = _target + "_shrubbery";
    out_file.open(file_name.c_str());

    if (out_file.is_open())
    {
        for (int i = 0; i < 5; i++)
        {
            out_file << "    *    " << std::endl;
            out_file << "   / \\   " << std::endl;
            out_file << "  /   \\  " << std::endl;
            out_file << " /     \\ " << std::endl;
            out_file << "/_______\\" << std::endl;
        }
        out_file.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
}