#include "DiamondTrap.hpp"

// CONSTRUCTOR

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	this->name = "name";

	ClapTrap::name = "generic_clap_name";

	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;

	std::cout << "DiamondTrap generic constructed!\n";
}

DiamondTrap::DiamondTrap(std::string init_name): ClapTrap(init_name), ScavTrap(init_name), FragTrap(init_name)
{
	this->name = "name";

	ClapTrap::name = init_name + "_clap_name";

	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;

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

void DiamondTrap::whoAmI( void )
{
	std::cout << this->name << " " << ClapTrap::name << "\n";
}
