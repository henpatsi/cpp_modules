/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:13 by hpatsi            #+#    #+#             */
/*   Updated: 2024/07/09 18:03:27 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

void create_and_print(std::string name, int grade)
{
	try
	{
		std::cout << "Creating bureaucrat with grade " << grade << "\n";
		Bureaucrat b = Bureaucrat(name, grade);
		std::cout << b << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\n";
}

int main()
{
	create_and_print("Henri", 42);
	create_and_print("Henri", 1);
	create_and_print("Henri", 150);
	create_and_print("Henri", 0);
	create_and_print("Henri", -42);
	create_and_print("Henri", 151);

	Bureaucrat one = Bureaucrat("Henri", 2);
	std::cout << one << "\n";
	try
	{
		std::cout << "Attempting to increment grade\n";
		one.incrementGrade();
		std::cout << one << "\n";
		std::cout << "Attempting to increment grade\n";
		one.incrementGrade();
		std::cout << one << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
		std::cout << one << "\n";
	}

	Bureaucrat onefifty = Bureaucrat("Henri", 149);
	std::cout << "\n" << onefifty << "\n";
	try
	{
		std::cout << "Attempting to decrement grade\n";
		onefifty.decrementGrade();
		std::cout << onefifty << "\n";
		std::cout << "Attempting to decrement grade\n";
		onefifty.decrementGrade();
		std::cout << onefifty << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
		std::cout << onefifty << "\n";
	}

	std::cout << "\nCopy test:\n";
	Bureaucrat copy = Bureaucrat(one);
	copy.decrementGrade();
	std::cout << "Copy: " << copy << "\n";
	std::cout << "Original: " << one << "\n";
	copy = onefifty;
	copy.incrementGrade();
	std::cout << "Copy: " << copy << "\n";
	std::cout << "Original: " << onefifty << "\n";
}
