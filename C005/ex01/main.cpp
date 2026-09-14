#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    std::cout << "======== TEST 1: Successful Signing ========" << std::endl;
    try {
        Bureaucrat director("Director", 10);
        Form taxForm("Tax Form 210", 45, 20);

        std::cout << taxForm << std::endl;
        
        // Director (grade 10) attempts to sign form (requires grade 45)
        // Since 10 <= 45, signing succeeds.
        director.signForm(taxForm);

        std::cout << taxForm << std::endl; // Should display [Signed: Yes]
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n======== TEST 2: Signing Failure (Grade Too Low) ========" << std::endl;
    try {
        Bureaucrat intern("Intern", 100);
        Form topSecretForm("Top Secret Document", 15, 5);

        std::cout << topSecretForm << std::endl;

        // Intern (grade 100) attempts to sign form (requires grade 15)
        // Since 100 > 15, signForm catches GradeTooLowException and prints error reason.
        intern.signForm(topSecretForm);

        std::cout << topSecretForm << std::endl; // Should remain [Signed: No]
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n======== TEST 3: Invalid Form Grade (Too High: 0) ========" << std::endl;
    try {
        // Constructor must throw GradeTooHighException
        Form invalidForm("Invalid", 0, 50);
    }
    catch (const std::exception& e) {
        std::cout << "Caught expected exception during Form construction: " << e.what() << std::endl;
    }

    std::cout << "\n======== TEST 4: Invalid Form Grade (Too Low: 151) ========" << std::endl;
    try {
        // Constructor must throw GradeTooLowException
        Form invalidForm2("Invalid2", 50, 151);
    }
    catch (const std::exception& e) {
        std::cout << "Caught expected exception during Form construction: " << e.what() << std::endl;
    }

    return 0;
}

