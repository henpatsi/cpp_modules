/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:26 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/04 16:06:33 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	const Point	a(0, 0);
	const Point	b(10, 0);
	const Point	c(10, 10);
	const Point point(5, 5);

	std::cout << bsp(a, b, c, point) << "\n";

	return 0;
}