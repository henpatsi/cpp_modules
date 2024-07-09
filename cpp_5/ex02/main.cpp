/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/07/09 21:59:02 by hpatsi           ###   ########.fr       */
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
	std::srand(time(NULL));

	//AForm form = AForm("Illegal Form", 150, 150);

	try_execute_all(Bureaucrat("150", 150));

	try_execute_all(Bureaucrat("140", 140));
	try_execute_all(Bureaucrat("130", 130));

	try_execute_all(Bureaucrat("70", 70));
	try_execute_all(Bureaucrat("40", 40));

	try_execute_all(Bureaucrat("20", 20));
	try_execute_all(Bureaucrat("1", 1));

	// Copy test
	Bureaucrat b = Bureaucrat("1", 1);

	ShrubberyCreationForm scf = ShrubberyCreationForm("shrubtarget");
	b.signForm(scf);
	b.executeForm(scf);
	ShrubberyCreationForm scf_copy = ShrubberyCreationForm(scf);
	ShrubberyCreationForm scf_copy2 = scf;

	std::cout << scf << "\n";
	std::cout << scf_copy << "\n";
	std::cout << scf_copy2 << "\n";
}
