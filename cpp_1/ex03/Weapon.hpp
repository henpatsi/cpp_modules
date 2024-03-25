#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon ( void );
		Weapon ( std::string type );

		std::string const&	getType( void );
		void	setType( std::string type );

	private:
		std::string	type;
};

#endif
