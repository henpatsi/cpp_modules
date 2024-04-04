/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:38 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/04 12:57:38 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	
	Fixed const add( Fixed( 5.1f ) + Fixed( 2 ) );
	std::cout << add << std::endl;
	Fixed const sub( Fixed( 5.1f ) - Fixed( 2 ) );
	std::cout << sub << std::endl;
	Fixed const mult( Fixed( 5.1f ) * Fixed( 2 ) );
	std::cout << mult << std::endl;
	Fixed const div( Fixed( 5.1f ) / Fixed( 2 ) );
	std::cout << div << std::endl;

	Fixed const x( Fixed( 1.5f ) * Fixed( 2.0f ) );
	std::cout << x << std::endl;
	Fixed const y( Fixed( 1.5f ) / Fixed( 2 ) );
	std::cout << y << std::endl;

	Fixed const bad( Fixed( 1.5f ) / Fixed() );
	std::cout << bad << std::endl;

	return 0;
}