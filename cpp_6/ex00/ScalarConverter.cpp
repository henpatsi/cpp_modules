/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:17:46 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/13 14:23:13 by hpatsi           ###   ########.fr       */
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
	try
	{
		i = std::stoi(input);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	catch (std::exception& e)
	{
		std::cout << "Not a valid integer\n";
		return (1);
	}
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
		std::cout << "Not a valid float\n";
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
		std::cout << "Not a valid double\n";
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
		if (!std::isdigit(str[i]) && !(i == 0 && str[i] == '-'))
			return (false);
	}
	return (true);
}

e_type get_type(std::string input)
{
	// char
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;

	// int
	if (str_is_num(input))
		return INT;
	
	// float
	// double
	size_t decimal_index = input.find(".");
	if (decimal_index != std::string::npos && str_is_num(input.substr(0, decimal_index)))
	{
		std::string end_substr = input.substr(decimal_index + 1, std::string::npos);
		if (str_is_num(end_substr))
			return DOUBLE;
		if (str_is_num(end_substr.substr(0, end_substr.length() - 1))
			&& end_substr[end_substr.length() - 1] == 'f')
			return FLOAT;
	}

	if (input == "-inff" || input == "+inff" || input == "nanf")
		return FLOAT;
	if (input == "-inf" || input == "+inf" || input == "nan")
		return DOUBLE;

	return NONE;
}

void print_conversion(char c, int i, float f, double d)
{
	// char
	if (d >= 0 && d <= 255 && std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else if (d >= 0 && d <= 255)
		std::cout << "char: " << "Non displayable\n";
	else
		std::cout << "char: " << "impossible\n";

	// int
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << "\n";
	else
		std::cout << "int: " << "impossible\n";
	
	// float
	// double
	std::cout << std::fixed; // Forces the use of decimal for f and d
	if (d == i)
	{
		std::cout << std::setprecision(1); // Adds .0 to end of float and double if int
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << d << "f\n";
	}
	else
	{
		std::string fstr = std::to_string(f);
		if (fstr.back() == '0')
		{
			if (fstr[fstr.find_last_not_of('0')] != '.')
				fstr.erase(fstr.find_last_not_of('0') + 1, std::string::npos);
			else
				fstr.erase(fstr.find_last_not_of('0') + 2, std::string::npos);
		}
		std::cout << "float: " << fstr << "f\n";
		
		std::string dstr = std::to_string(d);
		if (dstr.back() == '0')
		{
			if (dstr[dstr.find_last_not_of('0')] != '.')
				dstr.erase(dstr.find_last_not_of('0') + 1, std::string::npos);
			else
				dstr.erase(dstr.find_last_not_of('0') + 2, std::string::npos);
		}
		std::cout << "double: " << dstr << "\n";
	}
}

void ScalarConverter::convert ( std::string input )
{
	char	c;
	int		i;
	float	f;
	double	d;

	switch (get_type(input))
	{
		case CHAR:
			convert_char(input, c, i, f, d);
			break;
		case INT:
			if (convert_int(input, c, i, f, d) != 0)
				return ;
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

	print_conversion(c, i, f, d);
}
