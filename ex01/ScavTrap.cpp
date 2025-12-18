#include "ScavTrap.hpp"

/**
 * @brief Default constructor for ScavTrap
 * Initializes a ScavTrap with default values, inheriting from ClapTrap.
 */
ScavTrap::ScavTrap(void) : ClapTrap("Default")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called (" << name << ")\n";
}

/**
 * @brief Parameterized constructor for ScavTrap
 * Initializes a ScavTrap with a specific name.
 * @param name - The name of the ScavTrap
 */
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called (" << this->name << ")\n";
}

/**
 * @brief Copy constructor for ScavTrap
 * Creates a new ScavTrap as a copy of another.
 * @param other - The ScavTrap object to copy
 */
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called (" << name << ")\n";
}

/**
 * @brief Assignment operator for ScavTrap
 * Assigns the values of another ScavTrap to this one.
 * @param other - The ScavTrap object to assign from
 * @return Reference to the current object
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called (" << name << ")\n";
	return (*this);
}

/**
 * @brief Destructor for ScavTrap
 * Cleans up resources when the object is destroyed.
 */
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called (" << name << ")\n";
}

/**
 * @brief Attacks a target
 * Specialized attack for ScavTrap. Consumes 1 energy point.
 * @param target - The name of the target to attack
 */
void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " can't attack (no hit points left)\n";
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " can't attack (no energy points left)\n";
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!\n";
}

/**
 * @brief Activates Gate keeper mode
 * Prints a message indicating the ScavTrap is in Gate keeper mode.
 */
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
