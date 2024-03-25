#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	Zombie		*zombies;
	int			amount = 10;
	std::string	name = "Gregory";

	zombies = zombieHorde(amount, name);
	for (int i = 0; i < amount; i++)
	{
		zombies[i].announce();
	}
	delete[](zombies);
}