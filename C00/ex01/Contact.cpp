#include "Contact.hpp"

Contact::Contact(){

}

Contact::~Contact(){
    
}

void Contact::setName(std::string name){
    _name = name;
}

void Contact::setLastName(std::string lastName){
    _lastName = lastName;
}

void Contact::setNickName(std::string nickName){
    _nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber){
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret){
    _darkestSecret = darkestSecret;
}

std::string Contact::getName(){
    return (_name);
}

std::string Contact::getLastName(){
    return (_lastName);
}
std::string Contact::getNickName(){
    return (_nickName);
}
std::string Contact::getPhoneNumber(){
    return (_phoneNumber);
}
std::string Contact::getDarkestSecret(){
    return (_darkestSecret);
}


