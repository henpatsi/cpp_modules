/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:17:47 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/13 12:49:36 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE,
};

class ScalarConverter
{
	public:
		static void convert ( std::string input );
	
	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& );
		~ScalarConverter( void );
		ScalarConverter& operator=( const ScalarConverter& );
};

#endif
