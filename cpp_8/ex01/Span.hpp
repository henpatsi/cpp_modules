/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:41 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/04 11:08:01 by hpatsi           ###   ########.fr       */
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
		template <typename T>
		void addIteratorRange( T begin, T end )
		{
			if (this->vec.size() + std::distance(begin, end) > this->maximumSize)
				throw std::runtime_error("Range too large to be added to Span");

			for (T i = begin; i != end; i++)
			{
				this->vec.push_back(*i);
			}
		}

		unsigned int shortestSpan( void );
		unsigned int longestSpan ( void );

		void print( void );
	
	private:
		unsigned int maximumSize;
		std::vector<int> vec;
};

#endif
