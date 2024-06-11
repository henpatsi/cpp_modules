/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 14:57:27 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* scf;
	AForm* rrf;
	AForm* ppf;
	AForm* noform;

	scf = someRandomIntern.makeForm("shrubbery creation", "Carl");
	std::cout << *scf << "\n";
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << "\n";
	ppf = someRandomIntern.makeForm("presidential pardon", "Bob");
	std::cout << *ppf << "\n";
	noform = someRandomIntern.makeForm("wrong form name", "Bob");
	if (noform != nullptr)
		std::cout << *noform << "\n";
	
	Bureaucrat b = Bureaucrat("Henri", 10);

	b.signForm(*scf);
	b.signForm(*rrf);
	b.signForm(*ppf);

	b.executeForm(*scf);
	b.executeForm(*rrf);
	b.executeForm(*ppf);

	delete scf;
	delete rrf;
	delete ppf;
	delete noform;
}
