/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:00:00 by vflorez           #+#    #+#             */
/*   Updated: 2026/10/14 16:00:00 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
    private:
        // Un "creador" por cada tipo de formulario (misma firma para todos)
        AForm* createShrubbery(const std::string& target) const;
        AForm* createRobotomy(const std::string& target) const;
        AForm* createPresidential(const std::string& target) const;

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // Factory: devuelve un formulario nuevo en el heap (el llamador hace delete)
        AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
