/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:34:05 by vflorez           #+#    #+#             */
/*   Updated: 2026/10/14 14:30:00 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _isSigned;

    protected:
        // Paso variable del Template Method: cada hija define su accion
        virtual void executeAction() const = 0;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

    //getters
        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
    //modify states
        void beSigned(const Bureaucrat& bureaucrat);
    // Template Method: valida y luego llama a executeAction()
        void execute(const Bureaucrat& executor) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
            };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
            };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
            };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
