#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character( void );
		Character( std::string name );
		Character( const Character& );
		~Character( void );
		Character& operator=( const Character& );

		std::string const & getName( void ) const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );

	private:
		std::string name;
		AMateria* inventory[4] {};
};

#endif
