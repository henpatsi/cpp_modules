#include "AMateria.hpp"

// CONSTRUCTOR

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

// COPY

AMateria::AMateria(const AMateria& from)
{
	this->type = from.type;
}

// DESTRUCTOR

AMateria::~AMateria(void)
{
}

// OPERATOR

AMateria& AMateria::operator=(const AMateria& from)
{
	(void) from;
	return *this;
}

// MEMBER FUNCTIONS

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use( ICharacter& )
{
	std::cout << "Materia does not have a type, unable to use\n";
}
