/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:57 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/04 12:57:57 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed& );
		~Fixed( void );
		Fixed& operator=( const Fixed& );

		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );

	private:
		int fixed_point_value;
		static const int fractional_bits = 8;
};

#endif
