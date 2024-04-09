#include "DiamondTrap.hpp"

// CONSTRUCTOR

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	this->name = "name";

	ClapTrap::name = "generic_clap_name";

	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;

	std::cout << "DiamondTrap generic constructed!\n";
}

DiamondTrap::DiamondTrap(std::string init_name): ClapTrap(init_name), ScavTrap(init_name), FragTrap(init_name)
{
	this->name = "name";

	ClapTrap::name = init_name + "_clap_name";

	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;

	std::cout << "DiamondTrap " << ClapTrap::name << " constructed!\n";
}

// COPY

DiamondTrap::DiamondTrap(const DiamondTrap& from) : ScavTrap(from), FragTrap(from)
{
	this->ClapTrap::name = from.ClapTrap::name;
	std::cout << "DiamondTrap " << ClapTrap::name << " copy constructed!\n";
}

// DESTRUCTOR

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << ClapTrap::name << " destroyed!\n";
}

// OPERATOR

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& from)
{
	ClapTrap::operator=(from);
	this->ClapTrap::name = from.ClapTrap::name;
	std::cout << "DiamondTrap " << ClapTrap::name << " copy assigned!\n";
	return *this;
}

// MEMBER FUNCTIONS

void DiamondTrap::whoAmI( void )
{
	std::cout << this->name << " " << ClapTrap::name << "\n";
}
