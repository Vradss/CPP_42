/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:40:46 by vrads             #+#    #+#             */
/*   Updated: 2026/02/20 00:40:47 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "\n----- Test subject -----" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n----- Array of Animals -----" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	std::cout << "\n----- Sounds -----" << std::endl;
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	std::cout << "\n----- Deleting Animals -----" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n----- Deep Copy Test -----" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Chase the ball!");
	Dog dog2 = dog1;
	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	dog2.getBrain()->setIdea(0, "Eat food!");
	std::cout << "Dog1 after change: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 after change: " << dog2.getBrain()->getIdea(0) << std::endl;

	return 0;
}
