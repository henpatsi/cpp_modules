/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:32:06 by hpatsi            #+#    #+#             */
/*   Updated: 2024/03/19 14:50:20 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cctype>

bool	trim_str(std::string &str)
{
	char	spaces[6] = {' ', '\t', '\n', '\v', '\f', '\r'};
	size_t	n;

	n = str.find_first_not_of(spaces);
	if (n == std::string::npos)
		return (false);
	str.erase(0, n);
	n = str.find_last_not_of(spaces);
	str.erase(n + 1);
	return (true);
}

int main(int argc, char *argv[])
{
	bool	first;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		first = true;
		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			if (!trim_str(str))
				continue ;
			transform(str.begin(), str.end(), str.begin(), toupper);
			if (!first)
				std::cout << " ";
			else
				first = false;
			std::cout << str;
		}
		std::cout << "\n";
	}
	return (0);
}