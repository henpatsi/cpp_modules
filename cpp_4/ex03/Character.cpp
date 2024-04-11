#include "Character.hpp"

// CONSTRUCTOR

Character::Character(void)
{
	this->name = "Default";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

// COPY

Character::Character(const Character& from)
{
	(void) from;
}

// DESTRUCTOR

Character::~Character(void)
{

}

// OPERATOR

Character& Character::operator=(const Character& from)
{
	(void) from;
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
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx] == 0)
		return ;
	this->inventory[idx]->use(target);
}
