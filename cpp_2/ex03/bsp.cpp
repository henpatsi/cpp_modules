/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:23 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/05 09:48:44 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float triangle_area( Point const a, Point const b, Point const c )
{
	Fixed ax = a.get_x();
	Fixed ay = a.get_y();
	Fixed bx = b.get_x();
	Fixed by = b.get_y();
	Fixed cx = c.get_x();
	Fixed cy = c.get_y();

	Fixed result((ax * (by - cy) + bx * (cy - ay) + cx *(ay - by)) / 2.0f);

	if (result.toFloat() < 0)
		return (result.toFloat() * -1);
	return result.toFloat();
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed s1, s2, s3;
	
	if (point == a || point == b || point == c)
		return false;

	float total_area = triangle_area(a, b, c);
	float area1 = triangle_area(a, b, point);
	float area2 = triangle_area(a, c, point);
	float area3 = triangle_area(b, c, point);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	if (area1 + area2 + area3 != total_area)
		return false;

	return true;
}