#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    std::cout << "======== TEST 1: Successful Signing ========" << std::endl;
    try {
        Bureaucrat director("Director", 10);
        Form taxForm("Tax Form 210", 45, 20);

        std::cout << taxForm << std::endl;
        
        director.signForm(taxForm);

        std::cout << taxForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n======== TEST 2: Signing Failure (Grade Too Low) ========" << std::endl;
    try {
        Bureaucrat intern("Intern", 100);
        Form topSecretForm("Top Secret Document", 15, 5);

        std::cout << topSecretForm << std::endl;

        intern.signForm(topSecretForm);

        std::cout << topSecretForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n======== TEST 3: Invalid Form Grade (Too High: 0) ========" << std::endl;
    try {
        Form invalidForm("Invalid", 0, 50);
    }
    catch (const std::exception& e) {
        std::cout << "Caught expected exception during Form construction: " << e.what() << std::endl;
    }

    std::cout << "\n======== TEST 4: Invalid Form Grade (Too Low: 151) ========" << std::endl;
    try {
        Form invalidForm2("Invalid2", 50, 151);
    }
    catch (const std::exception& e) {
        std::cout << "Caught expected exception during Form construction: " << e.what() << std::endl;
    }

    return 0;
}

