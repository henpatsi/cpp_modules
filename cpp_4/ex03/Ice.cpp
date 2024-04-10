#include "Ice.hpp"

// CONSTRUCTOR

Ice::Ice(void) : AMateria("ice")
{
}

// COPY

Ice::Ice(const Ice& from)
{

}

// DESTRUCTOR

Ice::~Ice(void)
{

}

// OPERATOR

Ice& Ice::operator=(const Ice& from)
{

}

// MEMBER FUNCTIONS

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}