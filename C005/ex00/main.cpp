#include <iostream>
#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat Vrads("Vradis", 2);
        std::cout << Vrads << std::endl;
        
        // Testing grade modification
        Vrads.incrementGrade();
        std::cout << "After promotion: " << Vrads << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat boss("Boss", 0);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat intern("Intern", 151);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat chief("Chief", 1);
        chief.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;
    
    Bureaucrat bertha("Bertha", 6);
    bertha.decrementGrade(); 

    std::cout << "After promotion: " << bertha << std::endl;
    
    return 0;
}