#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& );
		~DiamondTrap( void );
		DiamondTrap& operator=( const DiamondTrap& );

		void whoAmI( void );

	private:
		std::string name;
};

#endif
