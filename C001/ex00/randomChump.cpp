/*Funcion que crea zombie en STACK*/
#include "Zombie.hpp"

void randomChump( std::string name ){
    Zombie zombie = Zombie(name); //aqui llamamos al constructor
    zombie.announce();
    return;
}
