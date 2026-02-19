/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:41:20 by vrads             #+#    #+#             */
/*   Updated: 2026/02/20 00:41:21 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// Animal es abstracta: solo usamos Dog y Cat como Animal*
	//const AAnimal* v = new AAnimal();
	std::cout << "----- Subject test -----" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;

	std::cout << "\n----- Polimorfismo: array de Animal* -----" << std::endl;
	AAnimal* animals[3];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();

	for (int idx = 0; idx < 3; idx++) {
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
	}
	for (int idx = 0; idx < 3; idx++)
		delete animals[idx];

	return 0;
}
