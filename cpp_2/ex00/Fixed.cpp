#include "Fixed.hpp"

// CONSTRUCTOR

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->fixed_point_value = 0;
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

// MEMBER FUNCTIONS

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_point_value);
}

void	Fixed::setRawBits ( int const raw )
{
	std::cout << "setRawBits member function called\n";
	this->fixed_point_value = raw;
}