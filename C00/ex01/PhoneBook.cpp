#include "PhoneBook.hpp"

Phonebook::Phonebook(){
    _contactCount = 0;
    _contactTotal = 0;
}
Phonebook::~Phonebook(){

}


void Phonebook::addContact(){
    std::string name, lastname,nickname, phone, secret;
    std::cout << "Name:" ;
    std::getline(std::cin, name);

    std::cout << "Last Name:" ;
    std::getline(std::cin, lastname);

    std::cout << "Nickname:" ;
    std::getline(std::cin, nickname);

    std::cout << "Phone Number:" ;
    std::getline(std::cin, phone);

    std::cout << "Darkest Secret:" ;
    std::getline(std::cin, secret);

    if (name.empty() || lastname.empty() || nickname.empty() || phone.empty() || secret.empty())
    {
        std::cout << "Error : All fields must be filled. Try ADD , SEARCH or EXIT" << std::endl;
        return;
    }

    _contacts[_contactCount].setName(name);
    _contacts[_contactCount].setLastName(lastname);
    _contacts[_contactCount].setNickName(nickname);
    _contacts[_contactCount].setPhoneNumber(phone);
    _contacts[_contactCount].setDarkestSecret(secret);

    _contactCount = (_contactCount + 1) % 8;
    if (_contactTotal < 8)
        _contactTotal++;

    std::cout << "Contact added succesfully!" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "What you want to do? Try ADD , SEARCH or EXIT" << std::endl;
}


void Phonebook::searchContact(){
    
    if (_contactTotal == 0)
    {
        std::cout << "No contact to display!. Please try ADD or EXIT" << std::endl;
        return ;
    }
    displayAllContacts();

    std::string input;
    int index;

    while (true) {
    std::cout << "Which contact are you looking for? ";
    std::getline(std::cin, input);
    
    std::stringstream ss(input);
    if (ss >> index) {
        if (index >= 0 && index < _contactTotal) {
            break;
        }
    }
    std::cout << "Invalid index. Try again: ";
}

    std::cout << std::endl;
    std::cout << "Contact Information:" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "First Name: " << _contacts[index].getName() << std::endl;
    std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "What you want to do? Try ADD, SEARCH or EXIT" <<std::endl;

}


std::string Phonebook::truncateString(std::string str){
    if (str.length() > 10)
        return (str.substr(0,9)+ ".");
    return (str);
}


void Phonebook::displayAllContacts(){
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "Name" << "|";
    std::cout << std::setw(10) << "LastName" << "|";
    std::cout << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;

    for ( int i = 0; i < _contactTotal; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateString(_contacts[i].getName()) << "|";
        std::cout << std::setw(10) << truncateString(_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateString(_contacts[i].getNickName()) << "|";
        std::cout << std::endl;
    }
}
