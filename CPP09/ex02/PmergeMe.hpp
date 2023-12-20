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
    public:
        std::list<int> X;
        std::list<std::pair<int, int> > pairs;
        size_t n;
        PmergeMe();
        ~PmergeMe();
        void Parse(int ac, char** av);
        void Divide(std::list<int> lst);
        void Swap(std::list<std::pair<int, int> > pair_lst);
        void Compare(std::list<std::pair<int, int> > pair_lst);
        void Binary(std::list<int>& big, std::list<int>& small);
        void printList(std::list<int> lst);
        void printPairs(std::list<std::pair<int, int> > pair_lst);
};

#endif