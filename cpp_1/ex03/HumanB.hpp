#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name );

		void	attack( void );
		void	setWeapon( Weapon& weapon );

	private:
		Weapon*		weapon;
		std::string	name;
};

#endif
