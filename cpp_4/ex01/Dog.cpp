/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:16:59 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/11 09:27:45 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// CONSTRUCTOR

Dog::Dog(void): Animal()
{
	this->type = "Dog";
	this->brain = new Brain();

	std::cout << "Dog constructed\n";
}

// COPY

Dog::Dog(const Dog& from): Animal(from)
{
	this->brain = new Brain(*from.brain);

	std::cout << "Dog copy constructed\n";
}

// DESTRUCTOR

Dog::~Dog(void)
{
	delete(this->brain);
	std::cout << "Dog destroyed\n";
}

// OPERATOR

Dog& Dog::operator=(const Dog& from)
{
	Animal::operator=(from);

	if (this != &from)
	{
		*this->brain = *from.brain;
	}

	std::cout << "Dog copy assignment\n";

	return *this;
}

// MEMBER FUNCTIONS

void Dog::makeSound(void) const
{
	std::cout << "Woof!\n";
}

Brain* Dog::getBrain( void )
{
	return this->brain;
}