#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <climits>
#include <list>

template <typename T>
void printContainer(const T& container)
{
    std::cout << "[ ";
    std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl;
}

int main()
{
    std::cout << std::endl << "--- Test subject ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    std::cout << std::endl << "--- Test 2 ---" << std::endl;
    try
    {
        const unsigned int size = 10000;

        std::srand(std::time(NULL));            

        std::vector<int> numbers;
        for (unsigned int i = 0; i < size; i++)
            numbers.push_back(std::rand());

        Span big(size);                         
        big.addRange(numbers.begin(), numbers.end());

        long shortest =  big.shortestSpan();
        long longest = big.longestSpan();

        std::cout << "shortest: " << shortest << std::endl;
        std::cout << "longest:  " << longest << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 3 Range ---" << std::endl;
    try
    {
        std::list<int> l;
        l.push_back(1);
        l.push_back(50);
        l.push_back(7);

        Span s(3);
        s.addRange(l.begin(), l.end());
        std::cout << "shortest: " << s.shortestSpan() << std::endl;
        std::cout << "longest:  " << s.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 4 Span lleno ---" << std::endl;
    try
    {
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 5 Rango que no cabe ---" << std::endl;
    try
    {
        std::vector<int> v(5, 1);
        Span small(3);
        small.addRange(v.begin(), v.end());
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 6 Duplicados ---" << std::endl;
    Span dup(3);
    dup.addNumber(5);
    dup.addNumber(5);
    dup.addNumber(10);
    std::cout << "shortest: " << dup.shortestSpan() << std::endl;

    std::cout << std::endl << "--- Test 7 INT_MIN / INT_MAX  ---" << std::endl;
    Span ext(2);
    ext.addNumber(INT_MIN);
    ext.addNumber(INT_MAX);
    std::cout << "longest: " << ext.longestSpan() << std::endl;

    return 0;
}
