#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class Phonebook{
private:
    Contact _contacts[8];
    int _contactCount;
    int _contactTotal;

    std::string truncateString(std::string str);
public:

    Phonebook();
    ~Phonebook();

    void addContact();
    void searchContact();
    void displayAllContacts();
};

#endif
