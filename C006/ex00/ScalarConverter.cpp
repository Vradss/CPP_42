/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:21:54 by vrads             #+#    #+#             */
/*   Updated: 2026/10/22 20:31:26 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//1.Othodox Canonical

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}


e_type ScalarConverter::detectType(const std::string& literal)
{
    if (isChar(literal))
        return CHAR;
    if (isInt(literal))
        return INT;
    if (isFloat(literal) || isPseudoFloat(literal))
        return FLOAT;
    if (isDouble(literal) || isPseudoDouble(literal))
        return DOUBLE;
    return INVALID;
}

//2. Verificamos si es Char, Int, float , pseudo y double
bool ScalarConverter::isChar(const std::string& s){
    return(s.length() == 1 && !std::isdigit(s[0]));

}
bool ScalarConverter::isInt(const std::string& n)
{
    if (n.empty())
        return false;

    size_t i  = 0;
    if ( n[i] == '+' || n[i] == '-')
        i++;
    if ( i == n.length())
        return false;
    while ( i < n.length())
    {
        if ( !std::isdigit(n[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isDouble(const std::string& d){
    if (d.empty())
        return false;

    size_t i = 0;
    int dots = 0;
    bool hasDigits = false;

    if ( d[i] == '+' || d[i] == '-')
        i++;

    while ( i < d.length())
    {
        if ( d[i] == '.')
            dots++;
        else if (std::isdigit(d[i]))
            hasDigits = true;
        else
            return false;
        i++;
    }
    return (dots == 1 && hasDigits );
}

bool ScalarConverter::isFloat(const std::string& f){
    if (f.empty())
        return false;

    if (f[f.length() - 1] != 'f')
        return false;

    return( isDouble(f.substr(0, f.length() - 1)));

}


bool ScalarConverter::isPseudoFloat(const std::string& p){
    return (p == "nanf" || p == "+inff" || p == "-inff" || p == "inff");
}

bool ScalarConverter::isPseudoDouble(const std::string& p){
    return (p == "nan" || p == "+inf" || p == "-inf" || p == "inf");
}


//3. Detectamos el tipo, lo pasamos a su tipo real y desde ahi lo casteamos a double
void ScalarConverter::convert(const std::string& literal)
{
    double d;

    switch (detectType(literal))
    {
        case CHAR: {
            char c = literal[0];
            d = static_cast<double>(c);
            break;
        }
        case INT: {
            long l = std::strtol(literal.c_str(), NULL, 10);
            if (l < INT_MIN || l > INT_MAX) {
                d = static_cast<double>(l);
                break;
            }
            int i = static_cast<int>(l);
            d = static_cast<double>(i);
            break;
        }
        case FLOAT: {
            float f = static_cast<float>(std::strtod(literal.c_str(), NULL));
            d = static_cast<double>(f);
            break;
        }
        case DOUBLE:
            d = std::strtod(literal.c_str(), NULL);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            return;
    }
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

//4. Imprimimos: cada print comprueba si el valor cabe ANTES de castear

void ScalarConverter::printChar(double d){
    std::cout << "char: ";
    if (d != d || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::printInt(double d){
    std::cout << "int: ";
    if (d != d || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

void ScalarConverter::printFloat(double d){
    std::cout << "float: ";
    if (d != d)
        std::cout << "nanf" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inff" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inff" << std::endl;
    else if (d < -FLT_MAX || d > FLT_MAX)
        std::cout << "impossible" << std::endl;
    else
    {
        float f = static_cast<float>(d);
        std::cout << f;
        //si no tiene decimales, cout imprime "42" y hay que añadir ".0"
        //(a partir de 1000000 cout pasa a notacion cientifica, ahi no se añade)
        if (f > -1000000 && f < 1000000 && f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d){
    std::cout << "double: ";
    if (d != d)
        std::cout << "nan" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else
    {
        std::cout << d;
        if (d > -1000000 && d < 1000000 && d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << std::endl;
    }
}
