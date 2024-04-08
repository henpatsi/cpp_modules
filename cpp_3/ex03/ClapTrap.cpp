/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:49:53 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/05 14:28:06 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// CONSTRUCTOR

ClapTrap::ClapTrap(void)
{
	this->name = "generic";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap " << this->name << " constructed!\n";
}

ClapTrap::ClapTrap( std::string name )
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap " << this->name << " constructed!\n";
}

// COPY

ClapTrap::ClapTrap(const ClapTrap& from)
{
	this->name = from.name;
	this->hitPoints = from.hitPoints;
	this->energyPoints = from.energyPoints;
	this->attackDamage = from.attackDamage;
	std::cout << "ClapTrap " << this->name << " copy constructed!\n";
}

// DESTRUCTOR

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destroyed!\n";
}

// OPERATOR

ClapTrap& ClapTrap::operator=(const ClapTrap& from)
{
	if (this != &from)
	{
		this->name = from.name;
		this->hitPoints = from.hitPoints;
		this->energyPoints = from.energyPoints;
		this->attackDamage = from.attackDamage;
	}
	std::cout << "ClapTrap " << this->name << " copy assigned!\n";
	return *this;
}

// MEMBER FUNCTIONS

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead!\n";
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points!\n";
		return;
	}

	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!\n";
		return;
	}

	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage!\n";

	if (this->hitPoints <= 0)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " was killed!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead!\n";
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points!\n";
		return;
	}

	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repaired " << amount << " damage!\n";
}