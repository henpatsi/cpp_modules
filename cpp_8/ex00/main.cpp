/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:57:38 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/29 16:35:50 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> arr{1, 2, 3, 4, 5};

	if (easyfind(arr, 3))
		std::cout << "Found 3!\n";
	else
		std::cout << "Did not find 3!\n";

	if (easyfind(arr, 8))
		std::cout << "Found 8!\n";
	else
		std::cout << "Did not find 8!\n";
	
	std::string str = "Hello";

	if (easyfind(str, 'e'))
		std::cout << "Found e!\n";
	else
		std::cout << "Did not find e!\n";

	if (easyfind(str, 'a'))
		std::cout << "Found a!\n";
	else
		std::cout << "Did not find a!\n";
}
