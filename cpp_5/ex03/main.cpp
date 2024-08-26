/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/07/09 22:03:18 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(time(NULL));

	Intern someRandomIntern;
	AForm* scf;
	AForm* rrf;
	AForm* ppf;
	AForm* noform;

	try
	{
		scf = someRandomIntern.makeForm("shrubbery creation", "Carl");
		std::cout << *scf << "\n";
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << "\n";
		ppf = someRandomIntern.makeForm("presidential pardon", "Bob");
		std::cout << *ppf << "\n";
		noform = someRandomIntern.makeForm("wrong form name", "Bob");
		std::cout << *noform << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Bureaucrat b = Bureaucrat("Henri", 10);
	std::cout << b << "\n";

	b.signForm(*scf);
	b.signForm(*rrf);
	b.signForm(*ppf);

	b.executeForm(*scf);
	b.executeForm(*rrf);
	b.executeForm(*ppf);

	delete scf;
	delete rrf;
	delete ppf;
}
