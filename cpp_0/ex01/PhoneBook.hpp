/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:45 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/21 09:25:38 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <cctype>

# include "Contact.hpp"

# define CONTACT_COUNT 8

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