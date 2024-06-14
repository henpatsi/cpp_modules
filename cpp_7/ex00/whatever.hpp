/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:36:03 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/14 14:41:53 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

template<typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}
