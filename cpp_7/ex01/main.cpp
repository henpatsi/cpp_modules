/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:46:51 by hpatsi            #+#    #+#             */
/*   Updated: 2024/08/29 09:51:06 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void print(const T& var)
{
	std::cout << var << "\n";
}

void increment(int &i)
{
	i++;
}

int main(void)
{
	int ints[] = {1, 2, 3, 4, 5};
	std::string strings[] = {"hello", "mom", "amazing", "wow!"};

	std::cout << "\n";
	iter(ints, 5, print);
	std::cout << "\n";
	iter(strings, 4, print);

	std::cout << "\n";
	iter(ints, 5, increment);
	iter(ints, 5, print);

	std::cout << "\n";
	const int constInts[] = {1, 2, 3, 4, 5};
	iter(constInts, 5, print);
}
