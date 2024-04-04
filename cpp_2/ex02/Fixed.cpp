/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:40 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/04 12:57:40 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTOR

Fixed::Fixed(void)
{
	this->fixed_point_value = 0;
}

Fixed::Fixed( const int initial_value )
{
	this->fixed_point_value = initial_value << this->fractional_bits;
}

Fixed::Fixed( const float initial_value )
{
	float rounded = roundf(initial_value * (1 << this->fractional_bits));
	this->fixed_point_value = (int) rounded;
}


// COPY

Fixed::Fixed(const Fixed& from)
{
	this->fixed_point_value = from.getRawBits();
}


// DESTRUCTOR

Fixed::~Fixed(void)
{

}


// OPERATOR

Fixed& Fixed::operator=(const Fixed& from)
{
	if (this != &from)
		this->fixed_point_value = from.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& from)
{
	out << from.toFloat();
	return out;
}

bool Fixed::operator>( const Fixed& other ) const
{
	return (this->fixed_point_value > other.fixed_point_value);
}

bool Fixed::operator<( const Fixed& other ) const
{
	return (this->fixed_point_value < other.fixed_point_value);
}

bool Fixed::operator>=( const Fixed& other ) const
{
	return (this->fixed_point_value >= other.fixed_point_value);
}

bool Fixed::operator<=( const Fixed& other ) const
{
	return (this->fixed_point_value <= other.fixed_point_value);
}

bool Fixed::operator==( const Fixed& other ) const
{
	return (this->fixed_point_value == other.fixed_point_value);
}

bool Fixed::operator!=( const Fixed& other ) const
{
	return (this->fixed_point_value != other.fixed_point_value);
}

Fixed Fixed::operator+( const Fixed& other ) const
{
	Fixed result;
	result.setRawBits(this->fixed_point_value + other.fixed_point_value);
	return result;
}

Fixed Fixed::operator-( const Fixed& other ) const
{
	Fixed result;
	result.setRawBits(this->fixed_point_value - other.fixed_point_value);
	return result;
}

Fixed Fixed::operator*( const Fixed& other ) const
{
	Fixed result(this->toFloat() * other.toFloat());
	return result;
}

Fixed Fixed::operator/( const Fixed& other ) const
{
	Fixed result(this->toFloat() / other.toFloat());
	return result;
}

Fixed& Fixed::operator++( void )
{
	++this->fixed_point_value;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed temp = *this;
	++this->fixed_point_value;
	return temp;
}

Fixed& Fixed::operator--( void )
{
	--this->fixed_point_value;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed temp = *this;
	--this->fixed_point_value;
	return temp;
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
	return this->fixed_point_value >> this->fractional_bits;;
}

float	Fixed::toFloat( void ) const
{
	return ((float) this->fixed_point_value / (float) (1 << this->fractional_bits));
}

Fixed& Fixed::min( Fixed &a, Fixed &b )
{
	return (a.fixed_point_value < b.fixed_point_value ? a : b);
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b )
{
	return (a.fixed_point_value < b.fixed_point_value ? a : b);
}

Fixed& Fixed::max( Fixed &a, Fixed &b )
{
	return (a.fixed_point_value > b.fixed_point_value ? a : b);
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
	return (a.fixed_point_value > b.fixed_point_value ? a : b);
}