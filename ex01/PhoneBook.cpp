#include "PhoneBook.hpp"

//inicializamos o asignamos?
PhoneBook::PhoneBook() : cur_contact(0) , index_contact(0) {}

//destructor no devuelve nada
PhoneBook::~PhoneBook() { return; }

void PhoneBook::addContact()
{
    if (cur_contact >= 8)
    {
        std::cout << "PhoneBook lleno. Reemplazando el contacto más antiguo." << std::endl;
        index_contact = 0; // Reinicia el índice para sobrescribir desde el inicio
        cur_contact = 8;   // Mantiene el contador en 8
    }
    
    Contact newContact;
    std::string input;
    
    std::cout << "Nombre: ";
    std::getline(std::cin, input);
    newContact.setName(input);
    
    std::cout << "Apellido: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);
    
    std::cout << "Apodo: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);
    
    std::cout << "Teléfono: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);
    
    std::cout << "Secreto más oscuro: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);
    
    // Agregar el contacto en la posición actual
    contacts[index_contact] = newContact;
    
    // Actualizar contadores
    index_contact = (index_contact + 1) % 8; // Circular: 0,1,2,3,4,5,6,7,0,1...
    if (cur_contact < 8)
        cur_contact++;
    
    std::cout << "\n¡Contacto agregado exitosamente!" << std::endl;
}

void PhoneBook::displayLastContact()
{
    if (cur_contact > 0)
    {
        int lastIndex = (index_contact - 1 + 8) % 8;  // El último contacto agregado
        std::cout << "\n=== CONTACTO RECIÉN AGREGADO ===" << std::endl;
        contacts[lastIndex].displayPerson();  // Usa TU función existente
    }
    else
    {
        std::cout << "No hay contactos para mostrar." << std::endl;
    }
}
