/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:32:06 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/18 20:04:29 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

std::string	trim_str(char *str)
{
	std::string new_str;
	size_t		n;

	new_str = (std::string) str;
	n = new_str.find_first_not_of(' ');
	new_str = &new_str[n];
	n = new_str.find_last_not_of(' ');
	new_str[n + 1] = 0;
	return (new_str);
}

int main(int argc, char *argv[])
{
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str = trim_str(argv[i]);
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout << str << " ";
		}
		std::cout << "\n";
	}
	return (0);
}