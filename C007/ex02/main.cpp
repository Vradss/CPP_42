/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:34:02 by vrads             #+#    #+#             */
/*   Updated: 2026/11/05 19:22:34 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"
#include <string>


template <typename T>
void printArray(const Array<T>& arr)
{
    std::cout << "[ ";
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << "] size = " << arr.size() << std::endl;
}

int main()
{
    std::cout << "=== Test 1: constructor sin parametros (array vacio) ===" << std::endl;
    Array<int> empty;
    printArray(empty);
    std::cout << std::endl;

    std::cout << "=== Test 2: constructor con n () ===" << std::endl;
    Array<int> a(5);
    printArray(a);
    std::cout << std::endl;

    std::cout << "=== Test 3: operator[] para modificar ===" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;
    printArray(a);
    std::cout << std::endl;

    std::cout << "=== Test 4: constructor de copia ===" << std::endl;
    Array<int> copy(a);
    copy[0] = 999;
    std::cout << "original: ";
    printArray(a);
    std::cout << "copia:    ";
    printArray(copy);
    std::cout << std::endl;

    std::cout << "=== Test 5: operador de asignacion brrr ===" << std::endl;
    Array<int> assigned(2);
    std::cout << "antes:    ";
    printArray(assigned);
    assigned = a;
    assigned[3] = 666;
    std::cout << "original: ";
    printArray(a);
    std::cout << "asignado: ";
    printArray(assigned);
    std::cout << std::endl;

    std::cout << "=== Test 6: indice fuera de rango ===" << std::endl;
    try
    {
        std::cout << "a[4] = " << a[4] << std::endl;
        std::cout << "intentando a[5]..." << std::endl;
        a[5] = 1; 
        std::cout << "esto no se imprime" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        empty[0] = 1;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception (empty array): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 7: const Array (evalua) ===" << std::endl;
    const Array<int> constArr(a);
    std::cout << "constArr[2] = " << constArr[2] << std::endl;
    //constArr[2] = 5; 
    std::cout << std::endl;

    std::cout << "=== Test 8: otro tipo (std::string) ===" << std::endl;
    Array<std::string> words(3);
    printArray(words);
    words[0] = "hola";
    words[1] = "soy";
    words[2] = "chevereee";
    printArray(words);
    std::cout << std::endl;

    return 0;
}