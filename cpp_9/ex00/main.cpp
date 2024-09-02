/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:37:07 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/02 22:46:57 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	try
	{
		BitcoinExchange btc(argv[1]);
	}
	catch(const BitcoinExchange::DataFormatException& e)
	{
		std::cerr << "DataFormatException: " << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
