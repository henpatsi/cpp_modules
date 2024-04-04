#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : weapon(weapon)
{
	this->name = name;
}

void	HumanA::attack( void )
{
	if (!this->weapon.getType().empty())
		std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
	else
		std::cout << this->name << " does not have a weapon\n";
}
