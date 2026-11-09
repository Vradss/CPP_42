#include "Span.hpp"


Span::Span() : _limit(0)
{}

Span::Span(unsigned int N) : _limit(N){}

Span::Span(const Span &other) : _limit(other._limit), _vec(other._vec) {}


Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _limit = other._limit;
        _vec = other._vec;
    }
    return *this;
}


Span::~Span() {}


void Span::addNumber(int n)
{
    if (_vec.size() >= _limit)
        throw FullException(); 
    _vec.push_back(n);
}

long Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw NotEnoughNumException();

    std::vector<int> copy = _vec;
    std::sort(copy.begin(), copy.end());

    long min = static_cast<long>(copy[1]) - copy[0];
    for (std::size_t i = 1; i < copy.size() - 1; i++)
    {
        long diff = static_cast<long>(copy[i + 1]) - copy[i];
        if (diff < min)
            min = diff;
    }
    return min;
}


long Span::longestSpan() const
{
    if ( _vec.size() < 2)  
        throw NotEnoughNumException();

    long max = *std::max_element(_vec.begin(), _vec.end());
    long min = *std::min_element(_vec.begin(), _vec.end());

    return max - min;
}


const char* Span::FullException::what() const throw()
{
    return "Span is full, no more space";
}

const char* Span::NotEnoughNumException::what() const throw()
{
    return "Span needs at least 2 numbers";
}
