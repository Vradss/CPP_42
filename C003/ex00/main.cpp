#include "ClapTrap.hpp"

int main()
{
    std::cout << "--- Creating ClapTrap ---" << std::endl;
    ClapTrap robot("Vrads");

    std::cout << "\n--- Attack test ---" << std::endl;
    robot.attack("Target1");
    robot.attack("Target2");

    std::cout << "\n--- Take damage test ---" << std::endl;
    robot.takeDamage(5);
    robot.takeDamage(3);

    std::cout << "\n--- Be repaired test ---" << std::endl;
    robot.beRepaired(4);

    std::cout << "\n--- Copy constructor test ---" << std::endl;
    ClapTrap copy(robot);
    copy.attack("CopyTarget");

    std::cout << "\n--- Assignment operator test ---" << std::endl;
    ClapTrap other("LadyGaga");
    other = robot;
    other.attack("AssignTarget");

    std::cout << "\n--- Exhaust energy test ---" << std::endl;
    ClapTrap robot3("Tori");
    for (int i = 0; i < 12; i++)
        robot3.attack("Victim");

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}
