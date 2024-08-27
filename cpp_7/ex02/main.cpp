/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:10:24 by hpatsi            #+#    #+#             */
/*   Updated: 2024/08/27 11:54:20 by hpatsi           ###   ########.fr       */
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
	// 0 size array

	Array<int> empty;
	try
	{
		std::cout << "Printing 0 size array index 0:\n";
		std::cout << empty[0] << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n\n";
	}

	// Empty array

	Array<int> ints(10);
	std::cout << "Empty array:\n";
	print_array(ints);

	// Copying

	Array<int> copy1(ints);
	std::cout << "Copy constucted:\n";
	print_array(copy1);
	for (size_t i = 0; i < copy1.size(); i++)
		copy1[i] = i;

	Array<int> copy2;
	copy2 = ints;
	std::cout << "Copy assigned:\n";
	print_array(copy2);
	for (size_t i = 0; i < copy2.size(); i++)
		copy2[i] = i * i;

	std::cout << "\nOriginal:\n";
	print_array(ints);
	std::cout << "Copy constructed modified:\n";
	print_array(copy1);
	std::cout << "Copy assigned modified:\n";
	print_array(copy2);

	// Index out of range
	
	try
	{
		std::cout << "\nPrinting 10 size array index 10:\n";
		std::cout << ints[10] << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		std::cout << "Printing 10 size array index -1:\n";
		std::cout << ints[-1] << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n\n";
	}

	// String array

	Array<std::string> strs(3);
	std::cout << "Empty string array size 3:\n";
	print_array(strs);
	Array<std::string> strscopy1(strs);
	Array<std::string> strscopy2;
	strscopy2 = strs;
	try
	{
		std::cout << "Try add \"hello\", \"it's\", \"me\", and \"you\"\n";
		strs[0] = "hello";
		strs[1] = "it's";
		strs[2] = "me";
		strs[3] = "you";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "Modified string array:\n";
	print_array(strs);
	std::cout << "Copy constructed original strings:\n";
	print_array(strscopy1);
	std::cout << "Copy assigned originial strings:\n";
	print_array(strscopy2);

	return 0;
}
