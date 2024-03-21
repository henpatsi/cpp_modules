/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:47 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/21 09:46:56 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	input_is_alpha(std::string str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
		{
			std::cout << "This field can only contain numbers\n";
			return (false);
		}
	}
	return (true);
}

bool	input_is_num(std::string str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isnumber(str[i]))
		{
			std::cout << "This field can only contain letters\n";
			return (false);
		}
	}
	return (true);
}

std::string	get_string_input(std::string prompt)
{
	std::string	input;
	
	do
	{
		std::cout << prompt << ":\n";
		if (!getline(std::cin, input))
			return (input);
	}
	while (!input_is_alpha(input));
	return (input);
}

std::string	get_num_input(std::string prompt)
{
	std::string	input;
	
	do
	{
		std::cout << prompt << ":\n";
		if (!getline(std::cin, input))
			return (input);
	}
	while (!input_is_num(input));
	return (input);
}

bool	PhoneBook::input_contact()
{
	Contact	contact;

	if (!contact.set_first_name(get_string_input("first_name")))
		return (false);
	if (!contact.set_last_name(get_string_input("last name")))
		return (false);
	if (!contact.set_nickname(get_string_input("nickname")))
		return (false);
	if (!contact.set_phone_number(get_num_input("phone")))
		return (false);
	if (!contact.set_darkest_secret(get_string_input("your darkest secret")))
		return (false);
	
	this->contacts[this->current_index] = contact;
	
	this->current_index++;
	if (this->current_index >= CONTACT_COUNT)
		this->current_index = 0;

	return (true);
}

bool	PhoneBook::search_contacts()
{
	for (int i = 0; i < CONTACT_COUNT; i++)
	{
		if (this->contacts[i].get_first_name().empty())
			break ;
		std::cout << i;
		std::cout << " " << this->contacts[i].get_first_name();
		std::cout << " " << this->contacts[i].get_last_name();
		std::cout << " " << this->contacts[i].get_nickname();
		std::cout << "\n";
	}

	return (true);
}
