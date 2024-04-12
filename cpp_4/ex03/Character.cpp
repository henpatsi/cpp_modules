#include "Character.hpp"

// CONSTRUCTOR

Character::Character(void)
{
	this->name = "Default";
}

Character::Character(std::string name)
{
	this->name = name;
}

// COPY

Character::Character(const Character& from)
{
	this->name = from.name;

	for (int i = 0; i < 4; i++)
	{
		if (from.inventory[i] != 0)
			this->inventory[i] = from.inventory[i]->clone();
	}
}

// DESTRUCTOR

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
			delete(this->inventory[i]);
	}
}

// OPERATOR

Character& Character::operator=(const Character& from)
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

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == 0)
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->inventory[idx] == 0)
		return ;
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->inventory[idx] == 0)
		return ;
	this->inventory[idx]->use(target);
}
