/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:21:20 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 14:55:35 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// CONSTRUCTOR

Intern::Intern(void)
{
}

// COPY

Intern::Intern(const Intern& from)
{
	(void) from;
}

// DESTRUCTOR

Intern::~Intern(void)
{
}

// OPERATOR

Intern& Intern::operator=(const Intern& from)
{
	(void) from;
	return *this;
}

// MEMBER FUNCTIONS

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm* form;

	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int formIndex = 0;
	for (std::string name : formNames)
	{
		if (formName == name)
			break ;
		formIndex++;
	}

	switch (formIndex)
	{
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break;
		default:
			throw InvalidNameException();
	}
	
	std::cout << "Intern creates " << form->getName() << " form\n";
	return form;
}

// EXCEPTIONS

const char* Intern::InvalidNameException::what() const throw()
{
	return "Invalid form name";
}