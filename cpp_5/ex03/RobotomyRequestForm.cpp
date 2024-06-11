/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:26 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 12:15:07 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// CONSTRUCTOR

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45)
{
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45)
{
	this->target = target;
}

// COPY

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& from) : RobotomyRequestForm(from.target)
{
}

// DESTRUCTOR

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

// OPERATOR

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& from)
{
	if (this != &from)
		this->target = from.target;
	return *this;
}

// MEMBER FUNCTIONS

void RobotomyRequestForm::executeFormAction( void ) const
{
	std::cout << "Bzzzzzz!" << "\n";

	int random_success = rand() % 100;
	if (random_success >= 50)
		std::cout << this->target << " has been robotomized successfully!" << "\n";
	else
		std::cout << this->target << " robotomy failed!" << "\n";
}
