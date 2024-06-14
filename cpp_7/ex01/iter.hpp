/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:47:01 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/14 15:10:37 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void iter(T* arr_ptr, int len, void (*func_ptr)(T))
{
	for (int i = 0; i < len; i++)
	{
		(*func_ptr)(arr_ptr[i]);
	}
}