#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& );
		~FragTrap( void );
		FragTrap& operator=( const FragTrap& );

		void highFivesGuys( void );
};

#endif
