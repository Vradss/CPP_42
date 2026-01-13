#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){

}

Weapon::~Weapon(){

}
//declare getType function
const std::string &Weapon::getType() const
{
    return type;
}

// declare set type function
void Weapon::setType(std::string newType)
{
    type = newType;
}
