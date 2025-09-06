#include "PhoneBook.hpp"

int main()
{
    Phonebook agenda;
    std::string command;
    
    std::cout << "Hey! What do you want to do?" << std::endl;
    std::cout << "Choose an option : ADD , SEARCH or EXIT" << std::endl;
    
    while(true){
        std::getline(std::cin, command);

        if (command == "ADD")
            agenda.addContact();
        else if (command == "SEARCH")
            agenda.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Wrong command, please only use : ADD , SEARCH or EXIT" << std::endl;
    }
    return 0;
}
