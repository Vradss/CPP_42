/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:40:33 by vrads             #+#    #+#             */
/*   Updated: 2026/02/20 00:40:34 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] Default constructor called" << std::endl;
	for (size_t i = 0; i < kIdeasSize; ++i)
		ideas[i] = "";
}

Brain::Brain(const Brain& other) {
	std::cout << "[Brain] Copy constructor called" << std::endl;
	for (size_t i = 0; i < kIdeasSize; ++i)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "[Brain] Copy assignment operator called" << std::endl;
	if (this != &other) {
		for (size_t i = 0; i < kIdeasSize; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}
