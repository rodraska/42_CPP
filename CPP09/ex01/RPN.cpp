#include "RPN.hpp"

RPN::RPN(char* input)
{
    this->_input = input;
}

RPN::~RPN()
{
}

int checkDigit(const char& c)
{
    if (c > 47 && c < 58)
        return (1);
    return (0);
}

int checkOperator(const char& c)
{
    if (c == 42 || c == 43 || c == 45 || c == 47)
        return (1);
    return (0);
}

void RPN::Parse()
{
    for (int i = 0; i < _input.length(); i++)
    {
        if (checkDigit(_input[i]))
            _stk.push(_input[i]);
    }
}

void RPN::printStack()
{
    while (_stk.size())
    {
        std::cout << _stk.top() << std::endl;
        _stk.pop();
    }
}