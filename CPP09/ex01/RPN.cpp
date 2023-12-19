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

void RPN::Calc()
{
    int first;
    int second;

    for (size_t i = 0; i < (size_t)_input.length(); i++)
    {
        if (checkDigit(_input[i]))
            _stk.push(_input[i] - 48);
        else if (checkOperator(_input[i]))
        {
            second = _stk.top();
            _stk.pop();
            first = _stk.top();
            _stk.pop();
            if (_input[i] == 45)
                _stk.push(first - second);
            else if (_input[i] == 43)
                _stk.push(first + second);
            else if (_input[i] == 42)
                _stk.push(first * second);
            else if (_input[i] == 47)
                _stk.push(first / second);
        }
        else if (_input[i] != 32)
        {
            std::cout << "Error" << std::endl;
            return ;
        }
    }
    std::cout << _stk.top() << std::endl;
}
