/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:00:00 by vflorez           #+#    #+#             */
/*   Updated: 2026/10/14 16:00:00 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// 1. Orthodox Canonical Form (el Intern no tiene atributos)
Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

// 2. Creadores: cada uno sabe construir un tipo concreto
AForm* Intern::createShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

// 3. makeForm (Factory)
// En vez de una cadena if/else if/else, dos tablas paralelas:
// nombre[i] <-> puntero a funcion miembro creators[i]
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (Intern::*creators[3])(const std::string&) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            AForm* form = (this->*creators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern couldn't create \"" << formName
              << "\" because that form doesn't exist" << std::endl;
    return NULL;
}
