#include "Zombie.hpp"

int main()
{
    std::cout << "\n===TEST 1 : NewZombie===" << std::endl;
    Zombie* heap1 = newZombie("Daniela");
    std::cout << "Zombie created in Heap" << std::endl;
    std::cout << "I can use it whenever i want" << std::endl;
    heap1->announce();
    std::cout << "I have to delete it" << std::endl;
    delete heap1;

    std::cout << "\n===TEST 2 : randomChump===" << std::endl;
    randomChump("Vica");

    return 0;
}
