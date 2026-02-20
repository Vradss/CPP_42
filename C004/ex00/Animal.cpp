/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:39:55 by vrads             #+#    #+#             */
/*   Updated: 2026/02/20 13:09:21 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "* generic animal sound *" << std::endl;
}
