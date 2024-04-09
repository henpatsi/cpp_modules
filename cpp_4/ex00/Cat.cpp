/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:16:57 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 12:36:04 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// CONSTRUCTOR

Cat::Cat(void): Animal()
{
	this->type = "Cat";

	std::cout << "Cat constructed\n";
}

// COPY

Cat::Cat(const Cat& from): Animal(from)
{
}

// DESTRUCTOR

Cat::~Cat(void)
{
	std::cout << "Cat destroyed\n";
}

// OPERATOR

Cat& Cat::operator=(const Cat& from)
{
	Animal::operator=(from);
	return *this;
}

// MEMBER FUNCTIONS

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}