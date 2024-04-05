#include "ScavTrap.hpp"

// CONSTRUCTOR

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap " << this->name << " constructed!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap " << this->name << " constructed!\n";
}

// COPY

ScavTrap::ScavTrap(const ScavTrap& from) : ClapTrap(from)
{
	std::cout << "ScavTrap " << this->name << " copy constructed!\n";
}

// DESTRUCTOR

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destroyed!\n";
}

// OPERATOR

ScavTrap& ScavTrap::operator=(const ScavTrap& from)
{
	ClapTrap::operator=(from);
	std::cout << "ScavTrap " << this->name << " copy assigned!\n";
	return *this;
}

// MEMBER FUNCTIONS

void	ScavTrap::guardGate(void)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead!\n";
		return;
	}

	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead!\n";
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points!\n";
		return;
	}

	this->energyPoints -= 1;
	std::cout << "ScavTrap " << this->name << " hugs " << target;
	std::cout << ", causing " << this->attackDamage << " points of lovely damage!\n";
}
