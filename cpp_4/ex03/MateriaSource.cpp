#include "MateriaSource.hpp"

// CONSTRUCTOR

MateriaSource::MateriaSource(void)
{
}

// COPY

MateriaSource::MateriaSource(const MateriaSource& from)
{
	for (int i = 0; i < 4; i++)
	{
		if (from.inventory[i] != 0)
			this->inventory[i] = from.inventory[i]->clone();
	}
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
	if (this != &from)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != 0)
				delete(this->inventory[i]);
		}

		for (int i = 0; i < 4; i++)
		{
			if (from.inventory[i] != 0)
				this->inventory[i] = from.inventory[i]->clone();
			else
				this->inventory[i] = 0;
		}
	}
	return *this;
}

// MEMBER FUNCTIONS

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == 0)
		return;
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
		if (this->inventory[i] == 0)
			continue;
		if (this->inventory[i]->getType() == type)
			return this->inventory[i]->clone();
	}
	return (0);
}
