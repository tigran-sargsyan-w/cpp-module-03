#include "FragTrap.hpp"

/**
 * @brief Default constructor for FragTrap.
 * Initializes a FragTrap with default values, inheriting from ClapTrap.
 */
FragTrap::FragTrap() : ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called (" << name << ")\n";
}

/**
 * @brief Parameterized constructor for FragTrap.
 * Initializes a FragTrap with a specific name.
 * @param name - The name of the FragTrap.
 */
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called (" << this->name << ")\n";
}

/**
 * @brief Copy constructor for FragTrap.
 * Creates a new FragTrap as a copy of another.
 * @param other - The FragTrap object to copy.
 */
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called (" << name << ")\n";
}

/**
 * @brief Assignment operator for FragTrap.
 * Assigns the values of another FragTrap to this one.
 * @param other - The FragTrap object to assign from.
 * @return Reference to the current object.
 */
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called (" << name << ")\n";
    return *this;
}

/**
 * @brief Destructor for FragTrap.
 * Cleans up resources when the object is destroyed.
 */
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called (" << name << ")\n";
}

/**
 * @brief Requests a positive high five.
 * Prints a message indicating the FragTrap is requesting a high five.
 */
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high five!\n";
}
