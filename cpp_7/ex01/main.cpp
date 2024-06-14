/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:46:51 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/14 15:09:50 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T var)
{
	std::cout << var << "\n";
}

int main(void)
{
	int ints[] = {1, 2, 3, 4, 5};
	std::string strings[] = {"hello", "mom", "amazing", "wow!"};

	iter(ints, 5, print);
	iter(strings, 4, print);
}
