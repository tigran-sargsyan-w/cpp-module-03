#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called (" << name << ")\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called (" << this->name << ")\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called (" << name << ")\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	std::cout << "ScavTrap assignment operator called (" << name << ")\n";
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called (" << name << ")\n";
}

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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
