#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
private:
    std::string name;
    Weapon& weapon; //tiene referencia a weapon porque no puede cambiar a otra arma

public:
    HumanA(std::string name, Weapon& weapon); //como humanA siempre tiene arma, nos olbiga a usar una referencia.
    ~HumanA();
    void attack() const;
};

#endif
