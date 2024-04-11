#include "MateriaSource.hpp"

// CONSTRUCTOR

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

// COPY

MateriaSource::MateriaSource(const MateriaSource& from)
{
	(void) from;
}

// DESTRUCTOR

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
			delete(this->inventory[i]);
	}
}

// OPERATOR

MateriaSource& MateriaSource::operator=(const MateriaSource& from)
{
		(void) from;
		return *this;
}

// MEMBER FUNCTIONS

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == 0)
		{
			this->inventory[i] = m->clone();
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i]->getType() == type)
			return this->inventory[i]->clone();
	}
	return (0);
}
