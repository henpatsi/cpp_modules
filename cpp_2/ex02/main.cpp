/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:38 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/05 10:05:17 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "\nIncrement/decrement:\n";
	std::cout << "  a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "  a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "  a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "  a-- = " << a-- << std::endl;
	std::cout << "  a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;

	std::cout << "\nMinmax:\n";
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "max a b = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min a b = " << Fixed::min( a, b ) << std::endl;
	
	std::cout << "\nMath:\n";
	Fixed const add( Fixed( 5.1f ) + Fixed( 2 ) );
	std::cout << "5.1 + 2 = " << add << std::endl;
	Fixed const sub( Fixed( 5.1f ) - Fixed( 2 ) );
	std::cout << "5.1 - 2 = " << sub << std::endl;
	Fixed const mult( Fixed( 5.1f ) * Fixed( 2 ) );
	std::cout << "5.1 * 2 = " << mult << std::endl;
	Fixed const div( Fixed( 5.1f ) / Fixed( 2 ) );
	std::cout << "5.1 / 2 = " << div << std::endl;
	Fixed const x( Fixed( 1.5f ) * Fixed( 2.0f ) );
	std::cout << "1.5 * 2 = " << x << std::endl;
	Fixed const y( Fixed( 1.5f ) / Fixed( 2 ) );
	std::cout << "1.5 / 2 = " << y << std::endl;

	Fixed one(1.0f);
	Fixed one1(1.0f);
	Fixed two(2.0f);

	std::cout << "\nEquality:\n";
	std::cout << "1 == 1: " << (one == one1) << "\n";
	std::cout << "1 == 2: " << (one == two) << "\n";
	std::cout << "1 != 1: " << (one != one1) << "\n";
	std::cout << "1 != 2: " << (one != two) << "\n";
	std::cout << "1 < 2: " << (one < two) << "\n";
	std::cout << "1 > 2: " << (one > two) << "\n";
	std::cout << "1 >= 1: " << (one >= one1) << "\n";
	std::cout << "1 >= 2: " << (one >= two) << "\n";
	std::cout << "1 <= 2: " << (one <= two) << "\n";

	return 0;
}