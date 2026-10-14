#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(NULL)); // una sola vez para toda la ejecucion

    std::cout << "======== TEST 1: Execute without signing ========" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        //boss.signForm(pardon);

        boss.executeForm(pardon);
    }

    std::cout << "\n======== TEST 2: Signed, but executor grade too low ========" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat clerk("Clerk", 140);
        ShrubberyCreationForm shrub("garden");

        clerk.signForm(shrub);    // 140 <= 145 -> firma
        clerk.executeForm(shrub); // 140 > 137  -> falla
        boss.executeForm(shrub);  // 1 <= 137   -> crea garden_shrubbery
    }

    std::cout << "\n======== TEST 3: Sign fails (grade too low) ========" << std::endl;
    {
        Bureaucrat intern("Intern", 150);
        RobotomyRequestForm robot("Bender");

        intern.signForm(robot);
        std::cout << robot << std::endl;
    }

    std::cout << "\n======== TEST 4: Robotomy x4 (50% chance) ========" << std::endl;
    {
        Bureaucrat engineer("Engineer", 45);
        RobotomyRequestForm robot("Bender");

        engineer.signForm(robot);
        for (int i = 0; i < 4; i++)
            engineer.executeForm(robot);
    }

    std::cout << "\n======== TEST 5: Presidential Pardon success ========" << std::endl;
    {
        Bureaucrat president("Zaphod", 5);
        PresidentialPardonForm pardon("Ford Prefect");

        president.signForm(pardon);
        president.executeForm(pardon);
    }

    std::cout << "\n======== TEST 6: Polymorphism through AForm* ========" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        AForm* forms[3];

        forms[0] = new ShrubberyCreationForm("home");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Trillian");
        for (int i = 0; i < 3; i++) {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]); // llama al executeAction de cada hija
        }
        for (int i = 0; i < 3; i++)
            delete forms[i]; // destructor virtual -> se destruye la hija tambien
    }

    return 0;
}
