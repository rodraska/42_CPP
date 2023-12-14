#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
    private:
        std::stack<int> _stk;
        std::string _input;
    public:
        RPN(char* input);
        ~RPN();

        void Parse();
        void printStack();
};

#endif