/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:22:00 by vrads             #+#    #+#             */
/*   Updated: 2026/10/19 18:07:54 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <limits>

enum e_type {CHAR, INT, FLOAT, DOUBLE, INVALID};

class ScalarConverter {
    private:
        //con el metho orthodoxical esta hecho para crear objetos, por eso iba tenia que ser accesible.
        //los ponemos en private porque no quiero crear objetos.
        //al ponerlas en privado, bloqueamos esta instanciacion
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        static bool isChar(const std::string& s);
        static bool isInt(const std::string& i);
        static bool isDouble(const std::string& d);
        static bool isFloat(const std::string& f);
        static bool isPseudoFloat(const std::string& p);
        static bool isPseudoDouble(const std::string& p);
        static e_type detectType(const std::string& literal);

        //print
        static void printChar(double d);
        static void printInt(double d);
        static void printFloat(double d);
        static void printDouble(double d);

        
    public:
        static void convert(const std::string& literal);
        
    };

    //Solo sirve para imprimir un objeto, pero no estamos creando objetos, entonces no sirve.
    //std::ostream& operator<<(std::ostream& out, const ScalarConverter& n);  

#endif