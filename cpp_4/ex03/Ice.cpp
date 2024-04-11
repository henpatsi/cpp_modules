#include "Ice.hpp"

// CONSTRUCTOR

Ice::Ice(void) : AMateria("ice")
{
}

// COPY

Ice::Ice(const Ice& from) : AMateria(from)
{
}

// DESTRUCTOR

Ice::~Ice(void)
{
}

// OPERATOR

Ice& Ice::operator=(const Ice& from)
{
	(void) from;
	return *this;
}

// MEMBER FUNCTIONS

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}