#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon& weapon );

		void	attack( void );
		void	setWeapon( Weapon& weapon );

	private:
		Weapon*		weapon;
		std::string	name;
};

#endif
