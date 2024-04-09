/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:50:05 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 12:31:49 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// CONSTRUCTOR

WrongCat::WrongCat(void): WrongAnimal()
{
	this->type = "WrongCat";

	std::cout << "WrongCat constructed\n";
}

// COPY

WrongCat::WrongCat(const WrongCat& from): WrongAnimal(from)
{
}

// DESTRUCTOR

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed\n";
}

// OPERATOR

WrongCat& WrongCat::operator=(const WrongCat& from)
{
	WrongAnimal::operator=(from);
	return *this;
}

// MEMBER FUNCTIONS

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow!\n";
}