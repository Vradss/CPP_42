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
        PresidentialPardonForm pardon("Lucas");
        //boss.signForm(pardon);

        boss.executeForm(pardon);
    }

    std::cout << "\n======== TEST 2: Signed, but executor grade too low ========" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat vrads("Vrads", 140);
        ShrubberyCreationForm shrub("garden");

        vrads.signForm(shrub);  
        vrads.executeForm(shrub);
        boss.executeForm(shrub);
    }

    std::cout << "\n======== TEST 3: Sign fails (grade too low) ========" << std::endl;
    {
        Bureaucrat intern("Intern", 150);
        RobotomyRequestForm robot("Ciboorg");

        intern.signForm(robot);
        std::cout << robot << std::endl;
    }

    std::cout << "\n======== TEST 4: Robotomy x4 (50% chance) ========" << std::endl;
    {
        Bureaucrat engineer("Engineer", 45);
        RobotomyRequestForm robot("Ciboorg");

        engineer.signForm(robot);
        for (int i = 0; i < 4; i++)
            engineer.executeForm(robot);
    }

    std::cout << "\n======== TEST 5: Presidential Pardon success ========" << std::endl;
    {
        Bureaucrat president("Zaphod", 5);
        PresidentialPardonForm pardon("Audrey Queen");

        president.signForm(pardon);
        president.executeForm(pardon);
    }

    std::cout << "\n======== TEST 6: Polymorphism through AForm* ========" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        AForm* forms[3];

        forms[0] = new ShrubberyCreationForm("home");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Lulita");
        for (int i = 0; i < 3; i++) {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
        }
        for (int i = 0; i < 3; i++)
            delete forms[i];
    }

    return 0;
}
