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
	int	integral_bits = (sizeof(int) * 8) - from.fractional_bits;
	int	decimal = from.fixed_point_value << integral_bits;

	if (decimal > 0)
		out << from.toFloat();
	else
		out << from.toInt();
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
	Fixed result( this->fixed_point_value + other.fixed_point_value );
	return result;
}

Fixed Fixed::operator-( const Fixed& other ) const
{
	Fixed result( this->fixed_point_value - other.fixed_point_value );
	return result;
}

Fixed Fixed::operator*( const Fixed& other ) const
{
	Fixed result( this->fixed_point_value * other.fixed_point_value );
	return result;
}

Fixed Fixed::operator/( const Fixed& other ) const
{
	Fixed result( this->fixed_point_value / other.fixed_point_value );
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
	return *this;
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

