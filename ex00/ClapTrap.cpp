#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called (" << name << ")\n";
}

ClapTrap::ClapTrap(const std::string &name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called (" << this->name << ")\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called (" << name << ")\n";
}

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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called (" << name << ")\n";
}

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
