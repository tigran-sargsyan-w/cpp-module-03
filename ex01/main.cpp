#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	std::cout << "\n--- Energy drain (ScavTrap) ---\n";
	ScavTrap c("C");
	for (int i = 0; i < 55; ++i)
		c.attack("wall");

	return 0;
}
