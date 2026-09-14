#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    // 1. Normal creation and operator<< test
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

    // 2. Testing Exception: Grade Too High (0)
    try {
        Bureaucrat boss("Boss", 0);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    // 3. Testing Exception: Grade Too Low (151)
    try {
        Bureaucrat intern("Intern", 151);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    // 4. Testing Exception on increment past boundary
    try {
        Bureaucrat chief("Chief", 1);
        chief.incrementGrade(); // Should throw (1 -> 0)
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    Bureaucrat bertha("Bertha", 6);
    bertha.incrementGrade(); 

    std::cout << "After promotion: " << bertha << std::endl;
    
    return 0;
}