/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:32:35 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/21 09:46:42 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	
	while (1)
	{
		std::cout << "Enter ADD, SEARCH, or EXIT\n";
		if (!getline(std::cin, input))
			break ;
		if (input == "ADD")
		{
			if (!phonebook.input_contact())
				break ;
		}
		else if (input == "SEARCH")
			phonebook.search_contacts();
		else if (input == "EXIT")
			break ;
	}
}