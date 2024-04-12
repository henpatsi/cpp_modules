#include "Cure.hpp"

// CONSTRUCTOR

Cure::Cure(void) : AMateria("cure")
{
}

// COPY

Cure::Cure(const Cure& from) : AMateria(from)
{
}

// DESTRUCTOR

Cure::~Cure(void)
{
}

// OPERATOR

Cure& Cure::operator=(const Cure&)
{
	return *this;
}

// MEMBER FUNCTIONS

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}