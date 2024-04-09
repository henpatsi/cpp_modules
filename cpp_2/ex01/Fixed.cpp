/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:51 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 08:59:47 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTOR

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->fixed_point_value = 0;
}

Fixed::Fixed( const int initial_value )
{
	std::cout << "Int constructor called\n";
	this->fixed_point_value = initial_value << this->fractional_bits;
}

Fixed::Fixed( const float initial_value )
{
	std::cout << "Float constructor called\n";
	float rounded = roundf(initial_value * (1 << this->fractional_bits));
	this->fixed_point_value = (int) rounded;
}

// COPY

Fixed::Fixed(const Fixed& from)
{
	std::cout << "Copy constructor called\n";
	this->fixed_point_value = from.getRawBits();
}

// DESTRUCTOR

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

// OPERATOR

Fixed& Fixed::operator=(const Fixed& from)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &from)
		this->fixed_point_value = from.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& from)
{
	out << from.toFloat();
	return out;
}

// MEMBER FUNCTIONS

int	Fixed::getRawBits( void ) const
{
	return (this->fixed_point_value);
}

void	Fixed::setRawBits ( int const raw )
{
	this->fixed_point_value = raw;
}

int	Fixed::toInt( void ) const
{
	int	int_value;

	int_value = this->fixed_point_value >> this->fractional_bits;
	return int_value;
}

float	Fixed::toFloat( void ) const
{
	return ((float) this->fixed_point_value / (float) (1 << this->fractional_bits));
}