/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:41 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/30 14:05:59 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class Span
{
	public:
		Span( void );
		Span( unsigned int size );
		Span( const Span& );
		~Span( void );
		Span& operator=( const Span& );

		void addNumber( int number );
		unsigned int shortestSpan( void );
		unsigned int longestSpan ( void );
	
	private:
		unsigned int maximumSize;
		std::vector<int> vec;

};

#endif
