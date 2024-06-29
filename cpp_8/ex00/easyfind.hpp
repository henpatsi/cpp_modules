/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:57:43 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/29 16:33:44 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>

template <typename T>
bool easyfind (T container, int i)
{
	if (std::find(container.begin(), container.end(), i) != container.end())
		return true;
	return false;
}

#endif
