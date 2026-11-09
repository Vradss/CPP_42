/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:00:00 by vrads             #+#    #+#             */
/*   Updated: 2026/11/05 21:53:21 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Value not found in container pipipi";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

template <typename T>
typename T::const_iterator easyfind(const T& container, int value);

#include "easyfind.tpp"

#endif
