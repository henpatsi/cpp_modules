/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:10:24 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/18 11:06:33 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

template <typename T>
void print_array(Array<T> arr)
{
	std::cout << "{";
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (i != 0)
			std::cout << ", ";
		std::cout << arr[i];
	}
	std::cout << "}\n";
}

int main(int, char**)
{
	Array<int> empty = Array<int>();
	try
	{
		std::cout << empty[0] << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	Array<int> ints = Array<int>(10);
	print_array(ints);

	Array<int> copy1 = Array<int>(ints);
	for (size_t i = 0; i < copy1.size(); i++)
		copy1[i] = i;

	Array<int> copy2 = Array<int>();
	copy2 = copy1;
	for (size_t i = 0; i < copy2.size(); i++)
		copy2[i] = i * i;

	print_array(ints);
	print_array(copy1);
	print_array(copy2);

	try
	{
		std::cout << ints[10] << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	Array<std::string> strs = Array<std::string>(3);
	print_array(strs);
	try
	{
		strs[0] = "hello";
		strs[1] = "it's";
		strs[2] = "me";
		strs[3] = "you";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	print_array(strs);

	return 0;
}
