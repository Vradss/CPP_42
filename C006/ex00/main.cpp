/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 20:29:13 by vrads             #+#    #+#             */
/*   Updated: 2026/10/22 20:30:21 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{

    if ( argc != 2)
    {
        std::cout << "Usage: ./Scalar <data>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;

}
