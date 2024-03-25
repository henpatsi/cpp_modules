#include "Zombie.hpp"

Zombie::~Zombie( void )
{
	std::cout << this->name << " destroyed!\n";
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
