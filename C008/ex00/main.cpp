/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:00:00 by vrads             #+#    #+#             */
/*   Updated: 2026/11/05 21:52:58 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>


template <typename T>
void printContainer(const T& container)
{
    std::cout << "[ ";
    std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl;
}

template <typename T>
void testFind(const T& container, int value)
{
    std::cout << "buscar " << value << ": ";
    try
    {
        typename T::const_iterator it = easyfind(container, value);
        std::cout << "encontrado en posicion " << std::distance(container.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    const int values[] = {10, 20, 30, 20, -42, 50};
    const int count = sizeof(values) / sizeof(values[0]);

    std::vector<int> vec(values, values + count);
    printContainer(vec);
    testFind(vec, 30);
    testFind(vec, 666);
    std::cout << std::endl;

    
    return 0;
}
