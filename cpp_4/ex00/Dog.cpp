/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:16:59 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 12:22:13 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// CONSTRUCTOR

Dog::Dog(void): Animal()
{
	this->type = "Dog";

	std::cout << "Dog constructed\n";
}

// COPY

Dog::Dog(const Dog& from): Animal(from)
{
}

// DESTRUCTOR

Dog::~Dog(void)
{
	std::cout << "Dog destroyed\n";
}

// OPERATOR

Dog& Dog::operator=(const Dog& from)
{
	Animal::operator=(from);
	return *this;
}

// MEMBER FUNCTIONS

void Dog::makeSound(void) const
{
	std::cout << "Woof!\n";
}