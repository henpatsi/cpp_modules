/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:17:27 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/13 13:49:31 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Use: ./converter <literal to convert>\n";
		return 1;
	}
	ScalarConverter::convert(argv[1]);

	// ScalarConverter converter = ScalarConverter(); // Cannot instantiate class
}
