/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:24 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 12:00:35 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// CONSTRUCTOR

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5)
{
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5)
{
	this->target = target;
}

// COPY

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& from) : PresidentialPardonForm(from.target)
{
}

// DESTRUCTOR

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

// OPERATOR

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& from)
{
	if (this != &from)
		this->target = from.target;
	return *this;
}

// MEMBER FUNCTIONS

void PresidentialPardonForm::executeFormAction( void ) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << "\n";
}
