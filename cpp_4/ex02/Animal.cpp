/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:16:55 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/11 09:29:20 by hpatsi           ###   ########.fr       */
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

	std::cout << "Animal copy constructed\n";
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

	std::cout << "Animal copy assignment\n";

	return *this;
}

// MEMBER FUNCTIONS

std::string Animal::getType(void) const
{
	return this->type;
}