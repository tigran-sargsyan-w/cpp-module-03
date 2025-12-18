#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap d("Ruby");

	d.attack("dummy");
	d.takeDamage(20);
	d.beRepaired(10);

	d.guardGate();
	d.highFivesGuys();

	d.whoAmI();

	return 0;
}
