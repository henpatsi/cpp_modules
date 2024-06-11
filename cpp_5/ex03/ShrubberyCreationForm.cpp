/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:28 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 12:43:49 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// CONSTRUCTOR

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137)
{
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137)
{
	this->target = target;
}

// COPY

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& from) : ShrubberyCreationForm(from.target)
{
}

// DESTRUCTOR

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

// OPERATOR

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& from)
{
	if (this != &from)
		this->target = from.target;
	return *this;
}

// MEMBER FUNCTIONS

void ShrubberyCreationForm::executeFormAction( void ) const
{
	std::ofstream outfile;
	outfile.open(this->target + "_shrubbery");
	if (!outfile.is_open())
	{
		std::cout << "Error opening file\n";
		return;
	}
	outfile << "   *      *\n";
	outfile << "  ***    ***\n";
	outfile << " *****  *****\n";
	outfile << "   |      |\n";
}
