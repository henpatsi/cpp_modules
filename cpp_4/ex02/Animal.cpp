/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:16:55 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 12:15:51 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// CONSTRUCTOR

Animal::Animal(void)
{
	std::cout << "Animal constructed\n";
}

// COPY

Animal::Animal(const Animal& from)
{
	this->type = from.type;
}

// DESTRUCTOR

Animal::~Animal(void)
{
	std::cout << "Animal destroyed\n";
}

// OPERATOR

Animal& Animal::operator=(const Animal& from)
{
	if (this != &from)
	{
		this->type = from.type;
	}
	return *this;
}

// MEMBER FUNCTIONS

void Animal::makeSound(void) const
{
	std::cout << "Generic animal noise!\n";
}

std::string Animal::getType(void) const
{
	return this->type;
}