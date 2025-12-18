#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("dummy");
	b.takeDamage(3);
	b.beRepaired(2);

	b.takeDamage(100);
	b.attack("someone");
	b.beRepaired(5);

	std::cout << "\n--- Energy drain test ---\n";
	ClapTrap c("C");
	for (int i = 0; i < 11; ++i)
		c.attack("wall");

	std::cout << "\n--- Copy test ---\n";
	ClapTrap d(c);
	ClapTrap e("E");
	e = a;

	return (0);
}
