/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:39:41 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/04 12:02:16 by hpatsi           ###   ########.fr       */
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
			if (m_vec.size() + std::distance(begin, end) > m_maximumSize)
				throw std::runtime_error("Range too large to be added to Span");
			m_vec.insert(m_vec.end(), begin, end);
		}

		unsigned int shortestSpan( void );
		unsigned int longestSpan ( void );

		void print( void );
	
	private:
		unsigned int m_maximumSize;
		std::vector<int> m_vec;
};

#endif
