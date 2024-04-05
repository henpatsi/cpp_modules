/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:26 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/05 09:47:06 by hpatsi           ###   ########.fr       */
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

	std::cout << "0, 0, on vertex: ";
	const Point point00(0, 0);
	std::cout << bsp(a, b, c, point00) << "\n";

	std::cout << "10, 0, on vertex: ";
	const Point point100(10, 0);
	std::cout << bsp(a, b, c, point100) << "\n";

	std::cout << "10, 10, on vertex: ";
	const Point point1010(10, 10);
	std::cout << bsp(a, b, c, point1010) << "\n";

	std::cout << "5, 9, outside: ";
	const Point point59(5, 9);
	std::cout << bsp(a, b, c, point59) << "\n";

	std::cout << "11, 1, outside: ";
	const Point point111(11, 1);
	std::cout << bsp(a, b, c, point111) << "\n";

	std::cout << "11, 11, outside: ";
	const Point point1111(11, 11);
	std::cout << bsp(a, b, c, point1111) << "\n";

	std::cout << "20, 20, outside: ";
	const Point point2020(20, 20);
	std::cout << bsp(a, b, c, point2020) << "\n";

	std::cout << "0, 5, ond edge: ";
	const Point point05(0, 5);
	std::cout << bsp(a, b, c, point05) << "\n";

	std::cout << "1, 1, ond edge: ";
	const Point point11(1, 1);
	std::cout << bsp(a, b, c, point11) << "\n";

	std::cout << "5, 5, on edge: ";
	const Point point55(5, 5);
	std::cout << bsp(a, b, c, point55) << "\n";

	std::cout << "10, 5, on edge: ";
	const Point point105(10, 5);
	std::cout << bsp(a, b, c, point105) << "\n";

	std::cout << "2, 1, inside: ";
	const Point point21(2, 1);
	std::cout << bsp(a, b, c, point21) << "\n";

	std::cout << "5, 3, inside: ";
	const Point point53(5, 3);
	std::cout << bsp(a, b, c, point53) << "\n";

	std::cout << "9, 5, inside: ";
	const Point point95(9, 5);
	std::cout << bsp(a, b, c, point95) << "\n";

	return 0;
}