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
		friend std::ostream& operator<<( std::ostream& out, const Fixed& );

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

	private:
		int fixed_point_value;
		static const int fractional_bits = 8;
};

#endif
