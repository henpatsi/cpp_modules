/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:57:38 by hpatsi            #+#    #+#             */
/*   Updated: 2024/08/30 10:04:53 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

#include "easyfind.hpp"

// class myclass
// {
// 	private:
// 		int x = 1;
// 		int y = 2;
// 		int z = 3;
// };

int main(void)
{
	// INT VECTOR TEST
	std::vector<int> vec{1, 2, 3, 4, 5};

	if (easyfind(vec, 3) != vec.end())
		std::cout << "Found 3!\n";
	else
		std::cout << "Did not find 3!\n";

	if (easyfind(vec, 8) != vec.end())
		std::cout << "Found 8!\n";
	else
		std::cout << "Did not find 8!\n";
	
	// STRING TEST
	std::string str = "Hello";

	if (easyfind(str, 'H') != str.end())
		std::cout << "Found 'H'!\n";
	else
		std::cout << "Did not find 'H'!\n";
	
	if (easyfind(str, 'Z') != str.end())
		std::cout << "Found 'Z'!\n";
	else
		std::cout << "Did not find 'Z'!\n";

	// // CUSTOM TYPE TEST
	// std::vector<myclass> myclass_vec;

	// if (easyfind(myclass_vec, 3))
	// 	std::cout << "Found 3!\n";
	// else
	// 	std::cout << "Did not find 3!\n";

	// if (easyfind(myclass_vec, 8))
	// 	std::cout << "Found 8!\n";
	// else
	// 	std::cout << "Did not find 8!\n";
}
