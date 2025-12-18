#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), FragTrap("Default"), ScavTrap("Default"), name("Default")
{
	hitPoints = 100;      // FragTrap
	energyPoints = 50;    // ScavTrap
	attackDamage = 30;    // FragTrap
	std::cout << "DiamondTrap constructor called (Default)" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& newName)
	: ClapTrap(newName + "_clap_name"), FragTrap(newName), ScavTrap(newName), name(newName)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor called (" << name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called (" << name << ")" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other); // virtual base is assigned once
		name = other.name;
	}
	std::cout << "DiamondTrap assignment operator called (" << name << ")" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called (" << name << ")" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name
			  << " | ClapTrap name: " << ClapTrap::name << std::endl;
}
