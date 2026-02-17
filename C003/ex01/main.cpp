#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "========== ClapTrap tests ==========" << std::endl;
    std::cout << "\n--- Creating ClapTrap ---" << std::endl;
    ClapTrap robot("Vrads");

    std::cout << "\n--- Attack test ---" << std::endl;
    robot.attack("Target1");

    std::cout << "\n--- Take damage & repair ---" << std::endl;
    robot.takeDamage(5);
    robot.beRepaired(4);

    std::cout << "\n========== ScavTrap tests  ==========" << std::endl;
    ScavTrap scav("Serena");

    std::cout << "\n--- ScavTrap attack ---" << std::endl;
    scav.attack("Enemy");

    std::cout << "\n--- Take damage & repair ---" << std::endl;
    scav.takeDamage(10);
    scav.beRepaired(5);

    std::cout << "\n--- ScavTrap guardGate ---" << std::endl;
    scav.guardGate();

    std::cout << "\n--- ScavTrap copy constructor ---" << std::endl;
    ScavTrap scavCopy(scav);
    scavCopy.attack("CopyTarget");

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}
