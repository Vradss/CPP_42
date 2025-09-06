#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string.h>

class Contact {
private:
    std::string name;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact(); //declaro constructor
    ~Contact(); // declaro destructor

    // SETTERS (para establecer los valores)
    void setName(const std::string& n);
    void setLastName(const std::string& ln);
    void setNickname(const std::string& nn);
    void setPhoneNumber(const std::string& pn);
    void setDarkestSecret(const std::string& ds);
    
    // GETTERS (para obtener los valores)
    std::string getName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    void displayPerson() const; // es const porque solo lee datos no modifica
    
};




#endif
