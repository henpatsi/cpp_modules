/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:57:11 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/05 09:06:16 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point( void );
		Point( const float x_value, const float y_value );
		Point( const Point& );
		~Point( void );
		Point& operator=( const Point& );

		bool operator==( const Point& ) const;

		Fixed get_x (void ) const;
		Fixed get_y (void ) const;

	private:
		const Fixed x;
		const Fixed y;
};

#endif
