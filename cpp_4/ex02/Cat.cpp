/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:16:57 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/10 12:53:28 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// CONSTRUCTOR

Cat::Cat(void): Animal()
{
	this->type = "Cat";
	this->brain = new Brain();

	std::cout << "Cat constructed\n";
}

// COPY

Cat::Cat(const Cat& from): Animal(from)
{
	this->brain = new Brain(*from.brain);
}

// DESTRUCTOR

Cat::~Cat(void)
{
	delete(this->brain);
	std::cout << "Cat destroyed\n";
}

// OPERATOR

Cat& Cat::operator=(const Cat& from)
{
	Animal::operator=(from);

	if (this != &from)
	{
		this->brain = new Brain(*from.brain);
	}

	return *this;
}

// MEMBER FUNCTIONS

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}