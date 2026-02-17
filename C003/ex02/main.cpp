#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "========== ClapTrap tests ==========" << std::endl;
    std::cout << "\n--- Creating ClapTrap ---" << std::endl;
    ClapTrap robot("Vrads");
    robot.attack("Target1");

    std::cout << "\n========== ScavTrap tests ==========" << std::endl;
    std::cout << "\n--- Creating ScavTrap (ClapTrap first, then ScavTrap) ---" << std::endl;
    ScavTrap scav("Serena");
    scav.attack("Enemy");
    scav.guardGate();

    std::cout << "\n========== FragTrap tests ==========" << std::endl;
    std::cout << "\n--- Creating FragTrap (ClapTrap first, then FragTrap) ---" << std::endl;
    FragTrap frag("Boom");
    frag.attack("Target");
    frag.highFivesGuys();

    std::cout << "\n--- FragTrap copy constructor ---" << std::endl;
    FragTrap fragCopy(frag);
    fragCopy.attack("CopyTarget");
    fragCopy.highFivesGuys();

    std::cout << "\n--- Destructors (FragTrap/ScavTrap first, then ClapTrap) ---" << std::endl;
    return 0;
}
