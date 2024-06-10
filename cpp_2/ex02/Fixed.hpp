/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:36 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/10 15:39:21 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const int initial_value );
		Fixed( const float initial_value );
		Fixed( const Fixed& );
		~Fixed( void );

		Fixed& operator=( const Fixed& );

		bool operator>( const Fixed& ) const;
		bool operator<( const Fixed& ) const;
		bool operator>=( const Fixed& ) const;
		bool operator<=( const Fixed& ) const;
		bool operator==( const Fixed& ) const;
		bool operator!=( const Fixed& ) const;

		Fixed operator+( const Fixed& ) const;
		Fixed operator-( const Fixed& ) const;
		Fixed operator*( const Fixed& ) const;
		Fixed operator/( const Fixed& ) const;

		Fixed& operator++( void );
		Fixed operator++( int );
		Fixed& operator--( void );
		Fixed operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed& min( Fixed &a, Fixed &b );
		static const Fixed& min( const Fixed &a, const Fixed &b );
		static Fixed& max( Fixed &a, Fixed &b );
		static const Fixed& max( const Fixed &a, const Fixed &b );
	private:
		int fixed_point_value;
		static const int fractional_bits = 8;
};

std::ostream& operator<<( std::ostream& out, const Fixed& );

#endif
