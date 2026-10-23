/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:00:00 by vrads             #+#    #+#             */
/*   Updated: 2026/10/23 14:00:00 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"

// Crea al azar un A, B o C y lo devuelve como Base*
Base* generate(void)
{
    switch (std::rand() % 3)
    {
        case 0:  std::cout << "generate: A" << std::endl; return new A;
        case 1:  std::cout << "generate: B" << std::endl; return new B;
        default: std::cout << "generate: C" << std::endl; return new C;
    }
}

// Con puntero: si el cast falla, dynamic_cast devuelve NULL
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

// Con referencia: no existe "referencia NULL", asi que si el cast
// falla lanza una excepcion (std::bad_cast). No podemos incluir
// <typeinfo>, por eso la capturamos con catch (...)
void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
    catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
    catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
    catch (...) {}
    std::cout << "Unknown" << std::endl;
}
