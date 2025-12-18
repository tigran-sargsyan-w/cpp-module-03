#include "ClapTrap.hpp"

/**
 * @brief Default constructor for ClapTrap.
 * Initializes a ClapTrap with default values.
 */
ClapTrap::ClapTrap()
	: name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called (" << name << ")\n";
}

/**
 * @brief Parameterized constructor for ClapTrap.
 * Initializes a ClapTrap with a specific name.
 * @param name - The name of the ClapTrap.
 */
ClapTrap::ClapTrap(const std::string &name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called (" << this->name << ")\n";
}

/**
 * @brief Copy constructor for ClapTrap.
 * Creates a new ClapTrap as a copy of another.
 * @param other - The ClapTrap object to copy.
 */
ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called (" << name << ")\n";
}

/**
 * @brief Copy assignment operator for ClapTrap.
 * Assigns the values of another ClapTrap to this one.
 * @param other - The ClapTrap object to assign from.
 * @return Reference to the current object.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

/**
 * @brief Destructor for ClapTrap.
 * Cleans up resources when the object is destroyed.
 */
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called (" << name << ")\n";
}

/**
 * @brief Attacks a target.
 * Consumes 1 energy point.
 * @param target - The name of the target to attack.
 */
void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't attack (no hit points left)\n";
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't attack (no energy points left)\n";
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!\n";
}

/**
 * @brief Takes damage from an attack.
 * Reduces hit points by the given amount.
 * @param amount - The amount of damage to take.
 */
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already destroyed (takes no more damage)\n";
		return ;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;

	std::cout << "ClapTrap " << name << " takes " << amount
			  << " damage, hit points now: " << hitPoints << "\n";
}

/**
 * @brief Repairs the ClapTrap.
 * Restores hit points and consumes 1 energy point.
 * @param amount - The amount of hit points to restore.
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair (no hit points left)\n";
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair (no energy points left)\n";
		return ;
	}
	energyPoints--;
	hitPoints += amount;

	std::cout << "ClapTrap " << name << " repairs itself for " << amount
			  << ", hit points now: " << hitPoints << "\n";
}
