/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:01:43 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/21 09:43:50 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::set_first_name(std::string name)
{
	if (name.empty())
		return (false);
	this->first_name = name;
	return (true);
}

bool	Contact::set_last_name(std::string name)
{
	if (name.empty())
		return (false);
	this->last_name = name;
	return (true);
}

bool	Contact::set_nickname(std::string name)
{
	if (name.empty())
		return (false);
	this->nickname = name;
	return (true);
}

bool	Contact::set_phone_number(std::string number)
{
	if (number.empty())
		return (false);
	this->phone_number = number;
	return (true);
}

bool	Contact::set_darkest_secret(std::string secret)
{
	if (secret.empty())
		return (false);
	this->darkest_secret = secret;
	return (true);
}

std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}
