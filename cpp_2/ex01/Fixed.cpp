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
	this->fixed_point_value = initial_value;
}

Fixed::Fixed( const float initial_value )
{
	std::cout << "Float constructor called\n";
	this->fixed_point_value = initial_value;
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
	out << from.getRawBits();
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
	return this->fixed_point_value;
}

float	Fixed::toFloat( void ) const
{
	return this->fixed_point_value;
}