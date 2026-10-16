/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:30:00 by vflorez           #+#    #+#             */
/*   Updated: 2026/10/14 18:03:06 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// 1. Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// 2. Getter
const std::string& ShrubberyCreationForm::getTarget() const { return _target; }

// 3. Accion concreta (AForm::execute ya valido firma y grado)
void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw ShrubberyCreationForm::FileOpenException();

    file << "       _-_       " << std::endl;
    file << "    /~~   ~~\\    " << std::endl;
    file << " /~~         ~~\\ " << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  / " << std::endl;
    file << "   ~  \\\\ //  ~   " << std::endl;
    file << "_- -   | | _- _  " << std::endl;
    file << "  _ -  | |   -_  " << std::endl;
    file << "      // \\\\      " << std::endl;
    file.close();
}

// 4. Exception
const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Could not open the shrubbery file!";
}
