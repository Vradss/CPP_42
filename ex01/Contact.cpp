#include "Contact.hpp"

Contact::Contact() { return; }

Contact::~Contact() { return; }

// SETTERS (para establecer los valores)
void Contact::setName(const std::string& n)
{
    name = n;
}
void Contact::setLastName(const std::string& ln)
{
    lastName = ln;
}
void Contact::setNickname(const std::string& nn)
{
    nickname = nn;
}
void Contact::setPhoneNumber(const std::string& pn)
{
    phoneNumber = pn;
}
void Contact::setDarkestSecret(const std::string& ds)
{
    darkestSecret = ds;
}
    
std::string Contact::getName() const { return name; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::displayPerson() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Las Name: " << lastName << std::endl;
    std::cout << "nickname: " << nickname << std::endl;
    std::cout << "Phone: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

