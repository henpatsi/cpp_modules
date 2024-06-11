/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 12:11:27 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void try_execute_all(Bureaucrat b)
{
	ShrubberyCreationForm scf = ShrubberyCreationForm("shrubtarget");
	RobotomyRequestForm rrf = RobotomyRequestForm("robottarget");
	PresidentialPardonForm ppf = PresidentialPardonForm("preztarget");

	b.signForm(scf);
	b.signForm(rrf);
	b.signForm(ppf);

	b.executeForm(scf);
	b.executeForm(rrf);
	b.executeForm(ppf);

	std::cout << "\n";
}

int main()
{
	srand(time(NULL));

	try_execute_all(Bureaucrat("150", 150));

	try_execute_all(Bureaucrat("140", 140));
	try_execute_all(Bureaucrat("130", 130));

	try_execute_all(Bureaucrat("70", 70));
	try_execute_all(Bureaucrat("40", 40));

	try_execute_all(Bureaucrat("20", 20));
	try_execute_all(Bureaucrat("1", 1));
}
