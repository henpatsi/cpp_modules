#include "AMateria.hpp"

// CONSTRUCTOR

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

// COPY

AMateria::AMateria(const AMateria& from)
{
}

// DESTRUCTOR

AMateria::~AMateria(void)
{

}

// OPERATOR

AMateria& AMateria::operator=(const AMateria& from)
{
	return *this;
}

// MEMBER FUNCTIONS

std::string const & AMateria::getType() const
{
	return this->type;
}
