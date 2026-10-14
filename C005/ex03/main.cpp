#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    std::srand(std::time(NULL)); // una sola vez para toda la ejecucion

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    std::cout << "======== TEST 1: Subject example (robotomy request) ========" << std::endl;
    {
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf; // el Intern crea con new: el llamador libera
        }
    }

    std::cout << "\n======== TEST 2: Every known form ========" << std::endl;
    {
        const std::string names[3] = {
            "shrubbery creation", "robotomy request", "presidential pardon"
        };
        for (int i = 0; i < 3; i++) {
            AForm* form = someRandomIntern.makeForm(names[i], "Marvin");
            if (form) {
                boss.signForm(*form);
                boss.executeForm(*form); // polimorfismo: executeAction de cada hija
                delete form;
            }
        }
    }

    std::cout << "\n======== TEST 3: Unknown form name ========" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("coffee request", "Boss");
        if (!form)
            std::cout << "makeForm returned NULL, nothing to delete" << std::endl;
    }

    std::cout << "\n======== TEST 4: Intern form, low-grade bureaucrat ========" << std::endl;
    {
        Bureaucrat clerk("Clerk", 140);
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (form) {
            clerk.signForm(*form);   // 140 > 25 -> falla
            boss.executeForm(*form); // no firmado -> falla
            delete form;
        }
    }

    return 0;
}
