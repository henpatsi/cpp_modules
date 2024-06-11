/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 10:46:54 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void create_and_print(std::string name, int signGrade, int executeGrade)
{
	try
	{
		std::cout << "Creating form with sign grade " << signGrade << " and execute grade " << executeGrade << "\n";
		Form f = Form(name, signGrade, executeGrade);
		std::cout << f << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
}

int main()
{
	create_and_print("Important Form", 1, 1);
	create_and_print("Important Form", 150, 150);
	create_and_print("Important Form", 0, 1);
	create_and_print("Important Form", 1, 0);
	create_and_print("Important Form", 151, 1);
	create_and_print("Important Form", 1, 151);
	std::cout << "\n";

	Bureaucrat b = Bureaucrat("Henri", 10);
	Form nine = Form("Important Form", 9, 6);

	std::cout << b << "\n";
	std::cout << nine << "\n";
	b.signForm(nine);
	std::cout << "\n";

	b.incrementGrade();
	std::cout << b << "\n";
	std::cout << nine << "\n";
	b.signForm(nine);
	std::cout << nine << "\n";

	std::cout << "\nCopy test:\n";
	Form copy = Form(nine);
	std::cout << copy << "\n";
}
