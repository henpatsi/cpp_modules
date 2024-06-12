/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:17:46 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/12 16:25:08 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int convert_char(std::string input, char& c, int& i, float& f, double& d)
{
	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	return (0);
}

int convert_int(std::string input, char& c, int& i, float& f, double& d)
{
	i = std::stoi(input);
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	return (0);
}

int convert_float(std::string input, char& c, int& i, float& f, double& d)
{
	try
	{
		f = std::stof(input);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Type could not be identified\n";
		return (1);
	}
	return (0);
}

int convert_double(std::string input, char& c, int& i, float& f, double& d)
{
	try
	{
		d = std::stod(input);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
	catch (std::exception& e)
	{
		std::cout << "Type could not be identified\n";
		return (1);
	}
	return (0);
}

bool	str_is_num(std::string str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && !(i == 0 && str[i] == '-'))
			return (false);
	}
	return (true);
}

e_type get_type(std::string input)
{
	if (input.length() == 1 && !str_is_num(input))
	{
		return CHAR;
	}
	else if (str_is_num(input))
	{
		return INT;
	}
	else if ((input.find(".") != std::string::npos && input.find("f") == std::string::npos)
			|| input == "-inf" || input == "+inf" || input == "nan")
	{
		return DOUBLE;
	}
	else if (input.find("f") != std::string::npos)
	{
		return FLOAT;
	}
	return NONE;
}

void ScalarConverter::convert ( std::string input )
{
	char	c = 0;
	int		i = 0;
	float	f = 0;
	double	d = 0;

	switch (get_type(input))
	{
	case CHAR:
		convert_char(input, c, i, f, d);
		break;
	case INT:
		convert_int(input, c, i, f, d);
		break;
	case FLOAT:
		if (convert_float(input, c, i, f, d) != 0)
			return ;
		break;
	case DOUBLE:
		if (convert_double(input, c, i, f, d) != 0)
			return ;
		break;
	default:
		std::cout << "Type could not be identified\n";
		return;
	}

	if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else if (!std::isnan(d) && !std::isinf(d))
		std::cout << "char: " << "Non displayable\n";
	else
		std::cout << "char: " << "impossible\n";
	
	if (!std::isnan(d) && !std::isinf(d))
		std::cout << "int: " << i << "\n";
	else
		std::cout << "int: " << "impossible\n";
	
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
	std::cout << "double: " << d << "\n";
}
