/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:47 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/21 12:03:02 by hpatsi           ###   ########.fr       */
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
			std::cout << "This field can only contain letters\n";
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
		if (!isdigit(str[i]))
		{
			std::cout << "This field can only contain numbers\n";
			return (false);
		}
	}
	return (true);
}

bool	input_is_print(std::string str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isprint(str[i]))
		{
			std::cout << "This field can only contain printable characters\n";
			return (false);
		}
	}
	return (true);
}

std::string	get_word_input(std::string prompt)
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

std::string	get_string_input(std::string prompt)
{
	std::string	input;
	
	do
	{
		std::cout << prompt << ":\n";
		if (!getline(std::cin, input))
			return (input);
	}
	while (!input_is_print(input));
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

	if (!contact.set_first_name(get_word_input("first name")))
		return (false);
	if (!contact.set_last_name(get_word_input("last name")))
		return (false);
	if (!contact.set_nickname(get_word_input("nickname")))
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

void	format_search_output(std::string str)
{
	if (str.length() < COLUMN_WIDTH)
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
	else
		std::cout << str.substr(0, 9) << ".";
}

void	print_contacts(Contact contacts[])
{
	for (int i = 0; i < CONTACT_COUNT; i++)
	{
		if (contacts[i].get_first_name().empty())
			break ;
		format_search_output(std::to_string(i + 1));
		std::cout << "|";
		format_search_output(contacts[i].get_first_name());
		std::cout << "|";
		format_search_output(contacts[i].get_last_name());
		std::cout << "|";
		format_search_output(contacts[i].get_nickname());
		std::cout << "\n";
	}
}

void	print_contact(Contact contact)
{
	std::cout << contact.get_first_name() << "\n";
	std::cout << contact.get_last_name() << "\n";
	std::cout << contact.get_nickname() << "\n";
	std::cout << contact.get_phone_number() << "\n";
	std::cout << contact.get_darkest_secret() << "\n";
}

bool	PhoneBook::search_contacts()
{
	std::string	input;
	int			index;

	print_contacts(this->contacts);

	while (1)
	{
		input = get_num_input("index");
		if (input.empty())
			return (false);
		index = stoi(input) - 1;
		if (index < 0 || index >= CONTACT_COUNT)
			std::cout << "Index out of range\n";
		else if (this->contacts[index].get_first_name().empty())
			std::cout << "No contact saved at given index\n";
		else
			break ;
	}

	print_contact(this->contacts[index]);

	return (true);
}
