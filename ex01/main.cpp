#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    
    std::cout << "=== AGREGAR CONTACTO ===" << std::endl;
    
    // Llamar directamente a addContact
    phonebook.addContact();

    std::cout << "\n=== MOSTRANDO CONTACTO ===" << std::endl;
    phonebook.displayLastContact();  // Muestra el contacto recién agregado
    
    
    std::cout << "\n¡Contacto agregado al PhoneBook!" << std::endl;
    
    return 0;
}
