#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string.h>
#include "Contact.hpp"


class PhoneBook {
private:
    Contact contacts[8];
    int cur_contact;
    int index_contact;
public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void displayLastContact();
    // void listContacto();

};




#endif
