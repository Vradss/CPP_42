/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:34:13 by vrads             #+#    #+#             */
/*   Updated: 2026/11/04 16:38:09 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Iter.hpp"
#include <string>


void printInt(const int &n)
{
    std::cout << n << " ";
}

void increment(int &num)
{
    num++;
}

void addExclamation(std::string &s)
{
    s += "!";
}


int main()
{
    std::cout << "=== Test 1: int[] + printConst ===" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printInt);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 2: int[] + noConst ===" << std::endl;
    iter(arr, 5, increment);
    iter(arr, 5, printInt);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 3: plantilla instanciada print<int> ===" << std::endl;
    iter(arr, 5, print<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 4: std::string[] ===" << std::endl;
    std::string words[] = {"hola", "que", "tal"};
    iter(words, 3, print<std::string>);
    std::cout << std::endl;
    iter(words, 3, addExclamation);
    iter(words, 3, print<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 5: const int[] v2 ===" << std::endl;
    const int carr[] = {10, 20, 30};
    iter(carr, 3, print<int>);
    //iter(carr, 3, increment); //no se puede modificar un const
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 6: otros tipos (char, double) ===" << std::endl;
    char letters[] = {'a', 'b', 'c'};
    double decimals[] = {1.5, 2.25, 3.75};
    iter(letters, 3, print<char>);
    std::cout << std::endl;
    iter(decimals, 3, print<double>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 7: casos limite ===" << std::endl;
    std::cout << "length 0: ";
    iter(arr, 0, printInt);
    std::cout << "(nada)" << std::endl;
    std::cout << "NULL: ";
    iter<int>(NULL, 3, printInt);
    std::cout << "(nada)" << std::endl;

    return 0;
}
