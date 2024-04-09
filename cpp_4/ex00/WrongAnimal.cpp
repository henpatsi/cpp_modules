/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:50:03 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 12:10:33 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// CONSTRUCTOR

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructed\n";
}

// COPY

WrongAnimal::WrongAnimal(const WrongAnimal& from)
{
	this->type = from.type;
}

// DESTRUCTOR

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed\n";
}

// OPERATOR

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& from)
{
	if (this != &from)
	{
		this->type = from.type;
	}
	return *this;
}

// MEMBER FUNCTIONS

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal noise!\n";
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}