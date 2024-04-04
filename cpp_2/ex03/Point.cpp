/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:09 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/04 15:28:03 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONSTRUCTOR

Point::Point(void) : x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const float x_value, const float y_value) : x(Fixed(x_value)), y(Fixed(y_value))
{
}

// COPY

Point::Point(const Point& from): x(Fixed(from.x)), y(Fixed(from.y))
{
}

// DESTRUCTOR

Point::~Point(void)
{
}

// OPERATOR

Point& Point::operator=(const Point&)
{
	return *this;
}

// MEMBER FUNCTIONS

Fixed Point::get_x(void) const
{
	return this->x;
}

Fixed Point::get_y(void) const
{
	return this->y;
}
