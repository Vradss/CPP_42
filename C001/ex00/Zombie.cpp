#include "Zombie.hpp"

//esta funciona es el constructos que se llama de randomChumo por ejemplo
//entonces cuando se termina osea se cierra el corchete }, se llama al destructor
Zombie::Zombie(std::string name){
     _name = name;
    std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
