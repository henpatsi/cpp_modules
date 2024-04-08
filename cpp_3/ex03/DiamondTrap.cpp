#include "DiamondTrap.hpp"

// CONSTRUCTOR

DiamondTrap::DiamondTrap(void)
{

}

DiamondTrap::DiamondTrap(std::string init_name): ClapTrap(init_name), ScavTrap(init_name), FragTrap(init_name)
{
	std::cout << "DiamondTrap " << init_name << " constructed!\n";
}

// COPY

DiamondTrap::DiamondTrap(const DiamondTrap& from)
{
	(void) from;
}

// DESTRUCTOR

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << "???" << " destroyed!\n";
}

// OPERATOR

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& from)
{
	(void) from;
	return *this;
}

// MEMBER FUNCTIONS

