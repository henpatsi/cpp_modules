/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:25:42 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/03 11:11:47 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// CONSTRUCTOR

RPN::RPN(std::string t_inputString)
{
	std::stringstream sstream(t_inputString);
	std::string arg;

	while (getline(sstream, arg, ' '))
	{
		if (arg.length() != 1)
			throw ArgumentException();

		if (std::isdigit(arg[0]))
		{
			m_stack.push(std::stoi(arg));
		}
		else if (std::find(RPN_OPERATORS.begin(), RPN_OPERATORS.end(), arg[0]) != RPN_OPERATORS.end())
			performCalculation(arg[0]);
		else
			throw ArgumentException();
	}

	if (m_stack.size() > 1)
		throw ArgumentException();

	std::cout << m_stack.top() << "\n";
}

// DESTRUCTOR

RPN::~RPN(void)
{
}

// MEMBER FUNCTIONS

void RPN::performCalculation(char t_operator)
{
	int var1;
	int var2;
	int result;

	if (m_stack.size() < 2)
		throw ArgumentException();

	var2 = m_stack.top();
	m_stack.pop();
	var1 = m_stack.top();
	m_stack.pop();

	switch (t_operator)
	{
		case '+':
			result = var1 + var2;
			break;
		case '-':
			result = var1 - var2;
			break;
		case '*':
			result = var1 * var2;
			break;
		case '/':
			result = var1 / var2;
			break;
	}

	m_stack.push(result);
}

// EXCEPTIONS

const char* RPN::ArgumentException::what() const throw()
{
	return "Error";
}
