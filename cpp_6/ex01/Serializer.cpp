/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:06:52 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/13 17:35:05 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr;

	ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}

