#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called (" << name << ")\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called (" << this->name << ")\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called (" << name << ")\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called (" << name << ")\n";
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called (" << name << ")\n";
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "FragTrap " << name << " can't attack (no hit points left)\n";
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "FragTrap " << name << " can't attack (no energy points left)\n";
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high five!\n";
}
