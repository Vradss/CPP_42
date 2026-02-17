#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is ready for action!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " says goodbye!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "FragTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " has no energy left and cannot attack!" << std::endl;
        return;
    }
    _energyPoints -= 1;
    std::cout << "FragTrap " << _name << " blasts " << target
              << " for " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}
