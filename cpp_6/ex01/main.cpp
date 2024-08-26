/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:10:17 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/13 17:33:09 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.x = 42;
	data.name = "henri";

	uintptr_t raw = Serializer::serialize(&data);
	Data* data_ptr = Serializer::deserialize(raw);

	std::cout << "data.x = " << data.x << "\n";
	std::cout << "&data = " << &data << "\n\n";
	
	std::cout << "serialized uint_ptr = " << raw << "\n";
	std::cout << "deserialized data_ptr = " << data_ptr << "\n\n";

	std::cout << "original == deserialized: " << (&data == data_ptr ? "True" : "False") << "\n";
	std::cout << "original.x = " << data.x << ", deserialized.x = " << data_ptr->x << "\n";
	std::cout << "original.name = " << data.name << ", deserialized.name = " << data_ptr->name << "\n";

	// Serializer s = Serializer(); // Cannot initialize
}
