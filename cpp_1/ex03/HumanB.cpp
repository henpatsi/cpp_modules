#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->name = name;
}

void	HumanB::attack( void )
{
	if (this->weapon && !this->weapon->getType().empty())
		std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
	else
		std::cout << this->name << " does not have a weapon\n";
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}
