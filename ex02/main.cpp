#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/**
 * @brief Main entry point
 * Demonstrates the functionality of ClapTrap, ScavTrap and FragTrap classes.
 * @return 0 on success
 */
int	main(void)
{
	std::cout << "\n--- ClapTrap basic ---\n";
	ClapTrap a("A");
	a.attack("dummy");
	a.takeDamage(3);
	a.beRepaired(2);

	std::cout << "\n--- ScavTrap chaining ---\n";
	ScavTrap b("B");
	b.attack("intruder");
	b.takeDamage(30);
	b.beRepaired(10);
	b.guardGate();

	std::cout << "\n--- FragTrap chaining ---\n";
	FragTrap c("C");
	c.attack("enemy");
	c.takeDamage(20);
	c.beRepaired(15);
	c.highFivesGuys();

	return 0;
}
