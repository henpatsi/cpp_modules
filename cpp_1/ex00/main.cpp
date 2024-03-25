#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	Zombie *zombie;

	zombie = newZombie("Harry");
	zombie->announce();
	delete(zombie);

	randomChump("Charlie");
}