#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const int initial_value );
		Fixed( const float initial_value );
		Fixed( const Fixed& );
		~Fixed( void );

		Fixed & operator=( const Fixed& );
		friend std::ostream& operator<<( std::ostream& out, const Fixed& );

		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

	private:
		int fixed_point_value;
		static const int fractional_bits = 8;
};

#endif
