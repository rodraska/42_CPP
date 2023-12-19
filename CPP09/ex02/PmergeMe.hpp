#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <string>
# include <iostream>
# include <list>
# include <sstream>
# include <iterator>

class PmergeMe
{
    private:
        std::list<int> X;
        std::list<int[2]> pairs;
        std::list<int> X2;
        std::list<int> S;
        size_t n;
    public:
        void Parse(int ac, char** av);
        void Print(std::list<int> lst);
        void Divide();
        std::list<int> getList(std::string str);
};

#endif