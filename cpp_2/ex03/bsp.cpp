/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:23 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/04 16:13:16 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// -5	*	0	-	-10	*	5	=	50
// -5	*	-10	-	-10	*	-5	=	0
// -5	*	-10	-	0	*	-5	=	50

Fixed sign ( Point const a, Point const b, Point const point)
{
	Fixed pointx = point.get_x();
	Fixed pointy = point.get_y();
	Fixed ax = a.get_x();
	Fixed ay = a.get_y();
	Fixed bx = b.get_x();
	Fixed by = b.get_y();

	return (pointx - bx) * (ay - by) - (ax - bx) * (pointy - by);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed s1, s2, s3;
	bool negative_sign;
	bool positive_sign;

	s1 = sign(a, b, point);
    s2 = sign(a, c, point);
    s3 = sign(b, c, point);

	negative_sign = s1 < 0 || s2 < 0 || s3 < 0;
	positive_sign = s1 > 0 || s2 > 0 || s3 > 0;

	if (negative_sign && positive_sign)
		return false;
	return true;
}