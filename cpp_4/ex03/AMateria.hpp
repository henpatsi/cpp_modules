#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria;

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string const type;
	
	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( const AMateria& );
		virtual ~AMateria( void );
		AMateria& operator=( const AMateria& );
	
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use( ICharacter& target );
};

#endif
