#include "AMateria.hpp"

// CONSTRUCTOR

AMateria::AMateria( void )
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

// COPY

AMateria::AMateria(const AMateria& from)  : type(from.type)
{
}

// DESTRUCTOR

AMateria::~AMateria(void)
{
}

// OPERATOR

AMateria& AMateria::operator=(const AMateria&)
{
	return *this;
}

// MEMBER FUNCTIONS

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use( ICharacter& )
{
}
