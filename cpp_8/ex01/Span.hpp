/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:41 by hpatsi            #+#    #+#             */
/*   Updated: 2024/08/30 14:48:02 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	public:
		Span( void );
		Span( unsigned int size );
		Span( const Span& );
		~Span( void );
		Span& operator=( const Span& );

		void addNumber( int number );
		void addIteratorRange( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		unsigned int shortestSpan( void );
		unsigned int longestSpan ( void );

		void print( void );
	
	private:
		unsigned int maximumSize;
		std::vector<int> vec;
};

#endif
