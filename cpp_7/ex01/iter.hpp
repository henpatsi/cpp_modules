/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:47:01 by hpatsi            #+#    #+#             */
/*   Updated: 2024/08/27 10:32:16 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T* arr, const size_t len, void (func)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void iter(const T* arr, const size_t len, void (func)(const T&))
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}


#endif
