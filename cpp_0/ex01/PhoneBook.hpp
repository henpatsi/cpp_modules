/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:45 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/21 11:12:03 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>

# include "Contact.hpp"

# define CONTACT_COUNT 8
# define COLUMN_WIDTH 10

class PhoneBook
{
	public:
		bool	input_contact();
		bool	search_contacts();

	private:
		int		current_index;
		Contact contacts[CONTACT_COUNT];
};

#endif