/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:28:28 by vrads             #+#    #+#             */
/*   Updated: 2026/11/04 15:28:31 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T*              _array;
        unsigned int    _size;
    
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T&              operator[](unsigned int index);
        const T&        operator[](unsigned int index) const;
        unsigned int    size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

#include "Array.tpp"

#endif