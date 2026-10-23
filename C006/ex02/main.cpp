/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:00:00 by vrads             #+#    #+#             */
/*   Updated: 2026/10/23 14:00:00 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
    std::srand(std::time(NULL));

    // 1. Casos conocidos: creamos A, B y C a mano
    Base* objs[3] = { new A, new B, new C };
    for (int i = 0; i < 3; i++)
    {
        std::cout << "identify(ptr): "; identify(objs[i]);
        std::cout << "identify(ref): "; identify(*objs[i]);
        delete objs[i];
    }
    std::cout << "----------------------------------------" << std::endl;

    // 2. Casos aleatorios: generate() decide el tipo real
    for (int i = 0; i < 5; i++)
    {
        Base* p = generate();
        std::cout << "identify(ptr): "; identify(p);
        std::cout << "identify(ref): "; identify(*p);
        delete p;
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;

    // 3. Puntero NULL: dynamic_cast devuelve NULL -> Unknown
    std::cout << "identify(NULL): "; identify((Base*)NULL);
    return 0;
}
