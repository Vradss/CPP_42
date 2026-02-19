/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:52:58 by vrads             #+#    #+#             */
/*   Updated: 2026/02/20 00:52:59 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(AMateria const& other) : _type(other._type) {}

AMateria& AMateria::operator=(AMateria const& other) {
	if (this != &other)
		; // copying the type doesn't make sense
	return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
