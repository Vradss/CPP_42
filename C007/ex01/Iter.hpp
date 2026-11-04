/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 13:25:55 by vrads             #+#    #+#             */
/*   Updated: 2026/11/03 12:23:25 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <cstddef>
#include <iostream>

//v1
template <typename T , typename F>
void iter( T *address, const size_t length, F func)
{
    if ( address == NULL)
        return;
    for (size_t i = 0; i < length; i++)
        func(address[i]);
}

//v2

template <typename T , typename F>
void iter( const T *address, const size_t length, F func)
{
    if ( address == NULL)
        return;
    for (size_t i = 0; i < length; i++)
        func(address[i]);
}

template <typename T>
void print(const T &x)
{
    std::cout << x << " ";
}
#endif

//sobrecarga: hemos creado dos iter, pero el compilador mira de que tipo array(const o no )es y elige la que encaja
//una vers recibe un puntero a T y otra un puntero a const T