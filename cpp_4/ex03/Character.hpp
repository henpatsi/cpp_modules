#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character
{
	public:
		Character( void );
		Character( const Character& );
		~Character( void );
		Character& operator=( const Character& );
};

#endif
