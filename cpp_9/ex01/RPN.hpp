/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:25:40 by hpatsi            #+#    #+#             */
/*   Updated: 2024/09/03 11:10:44 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <algorithm>

#ifndef RPN_OPERATORS
# define RPN_OPERATORS std::string("+-*/")
#endif

class RPN
{
	public:
		RPN(std::string t_inputString);
		~RPN(void);

		class ArgumentException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	private:
		RPN(void) = delete;
		RPN(const RPN&)  = delete;
		RPN& operator=(const RPN&)  = delete;

		std::stack<int> m_stack {};

		void performCalculation(char t_operator);
};

#endif
