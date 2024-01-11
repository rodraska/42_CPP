#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <string>
# include <iostream>
# include <list>
# include <sstream>
# include <iterator>
# include <deque>
# include <ctime>

class PmergeMe
{
    private:
        clock_t l_start;
        clock_t l_end;
        clock_t a_start;
        clock_t a_end;
    public:
        PmergeMe();
        ~PmergeMe();
        void Parse(int ac, char** av);
        void l_Divide(std::list<int> lst);
        void l_Swap(std::list<std::pair<int, int> >& pair_lst);
        void l_insertMain(std::list<std::pair<int, int> >& pair_lst);
        void l_insertPend(std::list<std::pair<int, int> >& pair_lst, std::list<int>& main);
        void l_printList(std::list<int> lst);
        void l_printPairs(std::list<std::pair<int, int> > pair_lst);

        void a_Divide(std::deque<int> lst);
        void a_Swap(std::deque<std::pair<int, int> >& pair_lst);
        void a_insertMain(std::deque<std::pair<int, int> >& pair_lst);
        void a_insertPend(std::deque<std::pair<int, int> >& pair_lst, std::deque<int>& main);
        void a_printList(std::deque<int> lst);
        void a_printPairs(std::deque<std::pair<int, int> > pair_lst);

        class BadArgumentsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class RepeatedArgumentsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif