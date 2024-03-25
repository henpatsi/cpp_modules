#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->type = type;
}

std::string const&	Weapon::getType( void )
{
	std::string const& typeref = this->type;
	return (typeref);
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}
