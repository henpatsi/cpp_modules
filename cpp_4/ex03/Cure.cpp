#include "Cure.hpp"

// CONSTRUCTOR

Cure::Cure(void) : AMateria("cure")
{
}

// COPY

Cure::Cure(const Cure& from)
{

}

// DESTRUCTOR

Cure::~Cure(void)
{

}

// OPERATOR

Cure& Cure::operator=(const Cure& from)
{

}

// MEMBER FUNCTIONS

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
}