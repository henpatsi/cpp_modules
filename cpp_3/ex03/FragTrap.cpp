#include "FragTrap.hpp"

// CONSTRUCTOR

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

	std::cout << "FragTrap " << this->name << " constructed!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

	std::cout << "FragTrap " << this->name << " constructed!\n";
}

// COPY

FragTrap::FragTrap(const FragTrap& from) : ClapTrap(from)
{
	std::cout << "FragTrap " << this->name << " copy constructed!\n";
}

// DESTRUCTOR

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destroyed!\n";
}

// OPERATOR

FragTrap& FragTrap::operator=(const FragTrap& from)
{
	ClapTrap::operator=(from);
	std::cout << "FragTrap " << this->name << " copy assigned!\n";
	return *this;
}

// MEMBER FUNCTIONS

void FragTrap::highFivesGuys(void)
{
	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " is dead!\n";
		return;
	}

	std::cout << "FragTrap " << this->name << " asks for high fives (positively)!\n";
}