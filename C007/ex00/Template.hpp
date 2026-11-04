/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 13:24:40 by vrads             #+#    #+#             */
/*   Updated: 2026/11/03 10:51:16 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
#include <string>


template <typename T>
void swap(T &x, T &y )
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
const T &min(const T &x, const T &y) 
{
    if ( x >= y)
        return y;
    else
        return x;
}

template <typename T>
const T &max(const T &x, const T &y)
{
    if ( x > y)
        return x;
    return y;

}

#endif