#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <iterator> 


class Span
{
    private:
        unsigned int _limit;
        std::vector<int> _vec;

    public:

        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int);
        long int shortestSpan() const;
        long int longestSpan() const;


        template <typename T>
        void addRange(T begin, T end);

        class FullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NotEnoughNumException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};


#include "Span.tpp"

#endif
